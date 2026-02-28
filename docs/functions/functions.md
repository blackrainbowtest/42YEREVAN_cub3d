<a name="top"></a>
# [⬅️ Back to Main Documentation](../README.md)

# Functions Used in main.c

## MiniLibX Functions

- `mlx_init()`: Initializes MiniLibX and returns a pointer to the library context. Returns NULL if failed.

## Example Usage
```c
void *mlx_ptr = mlx_init();
if (NULL == mlx_ptr)
    return (1);
```


---

- `mlx_destroy_display(void *mlx_ptr)`: Destroys the display associated with the MiniLibX context and frees related resources allocated by X11. This function cleans up the graphical display, but does not free the mlx_ptr itself. After calling `mlx_destroy_display`, you should also call `free(mlx_ptr)` to fully release all memory used by MiniLibX and avoid memory leaks.

## Example Usage
```c
void *mlx_ptr = mlx_init();
if (NULL == mlx_ptr)
    return (1);
// ... other code ...
mlx_destroy_display(mlx_ptr);
```


---

- `mlx_new_window(void *mlx_ptr, int width, int height, char *title)`: Creates a new window with the given width, height, and title, using the MiniLibX context. Returns a pointer to the window, or NULL if creation fails.

- `mlx_loop(void *mlx_ptr)`: Starts the event loop for the MiniLibX context. This function keeps the window open and processes events until the program is terminated.

## Example Usage (Error Handling)
```c
#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400

int main(void)
{
    void *mlx_connection;
    void *mlx_window;

    mlx_connection = mlx_init();
    if (NULL == mlx_connection)
        return (MALLOC_ERROR);
    mlx_window = mlx_new_window(mlx_connection, HEIGHT, WIDTH, "cube3d");
    if (NULL == mlx_window)
    {
        mlx_destroy_display(mlx_connection);
        free(mlx_connection);
        return (MALLOC_ERROR);
    }
    mlx_loop(mlx_connection);
}
```

More functions will be documented as we use them in the project.
