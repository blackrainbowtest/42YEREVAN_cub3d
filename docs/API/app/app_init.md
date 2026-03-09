<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# app_init

Declaration:
`
int app_init(t_data *d);
`

Purpose:

Initializes the core application context and prepares all runtime systems required by the engine.

This function performs the following tasks:

- initializes internal state variables
- initializes the MLX graphics context
- creates the main window
- creates the main image buffer used for rendering
- retrieves the pixel buffer address

The function must be called BEFORE starting the main event loop.


Parameters:
`
d
`
Pointer to the global application context.

Expected type:
```c
t_data *
```
This structure stores the global engine state including:

- MLX graphics context
- rendering buffers
- map data
- player data
- input state
- application exit code


Return Value:

Returns 0 if initialization succeeds.

Returns MLX_ERROR if any of the MLX initialization steps fail.


Initialization Steps:

The function initializes several engine subsystems in a specific order.


1. Reset engine state
```c
d->exit_code = 0;
```
Initializes the application exit code.

This value will later be used when calling clean_exit().


2. Reset movement state

d->move.forward = 0;
d->move.backward = 0;
d->move.turn_left = 0;
d->move.turn_right = 0;

All input flags are reset to zero.

This ensures that the player starts with no active movement.

Movement flags will later be updated by input hooks.


3. Initialize window dimensions
```c
d->mlx.w = WINDOW_WIDTH;
d->mlx.h = WINDOW_HEIGHT;
```
Sets the rendering resolution for the main window.

These values are defined in the project configuration:
```
WINDOW_WIDTH
WINDOW_HEIGHT
```

4. Initialize MLX context
```c
d->mlx.mlx = mlx_init();
```
Creates the MLX graphics context.

This context represents the connection between the program and the windowing system.

If this step fails the program cannot create windows or render graphics.


5. Create main window
```c
d->mlx.win = mlx_new_window(d->mlx.mlx, d->mlx.w, d->mlx.h, "cub3d");
```
Creates the main application window.

Parameters:

mlx context
window width
window height
window title


6. Create render image buffer
```c
d->img.img = mlx_new_image(d->mlx.mlx, d->mlx.w, d->mlx.h);
```
Creates an off-screen image buffer.

This buffer is used for rendering pixels before displaying them in the window.

Rendering directly to the window is inefficient, therefore the engine draws to this image first.


7. Retrieve pixel buffer address
```c
d->img.addr = mlx_get_data_addr(
    d->img.img,
    &d->img.bpp,
    &d->img.line_len,
    &d->img.endian
);
```
Retrieves the memory address of the image pixel buffer.

This allows the engine to write pixel data directly into the image.

Returned metadata:

`bpp`
Bits per pixel.

`line_len`
Number of bytes in one row of pixels.

`endian`
Byte order of the pixel format.


Rendering Model:

The engine uses an off-screen rendering model.

Rendering pipeline:

`draw pixels` -> `image buffer` -> `mlx_put_image_to_window`


Error Handling:

Each MLX initialization step is validated.

If any step fails the function returns MLX_ERROR.

This allows the caller to terminate the program safely.


Example Usage:

`t_data d;`

```
if (app_init(&d) != 0)
    return (1);
```
After successful initialization the engine can proceed with:

- hook registration
- map loading
- starting the main loop


Engine Architecture Role:

`app_init()` is the entry point of the rendering subsystem.

It prepares:

- graphics context
- window
- render buffer
- input state

Without this initialization the engine cannot start the event loop.

Simplified Execution Flow:

`main()` ->
`app_init()` ->
`register hooks` ->
`mlx_loop()`


Short Summary:

`app_init()` initializes the entire runtime environment required by the cub3d engine.

It prepares graphics, input state, and rendering buffers before the game loop begins.

[⬆️ Back to Top](#top)