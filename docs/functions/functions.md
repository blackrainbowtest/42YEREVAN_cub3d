# [Back to Main Documentation](../README.md)
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

More functions will be documented as we use them in the project.
