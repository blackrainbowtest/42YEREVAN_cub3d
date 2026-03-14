<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# app_init

Declaration:
```c
int app_init(t_data *d);
```

Summary:

Initializes graphics runtime objects required before entering the main loop.

Parameters:

`d` - global application context.

Return value:

`0` on success, `ERROR` on failure.

Flow:

1. Set window size from project constants.
2. Create MLX context.
3. Create window.
4. Create image buffer.
5. Fetch image pixel address and metadata.
6. Initialize camera plane from current direction.

Notes:

If any MLX step fails, the function returns `ERROR` immediately.

[⬆️ Back to Top](#top)