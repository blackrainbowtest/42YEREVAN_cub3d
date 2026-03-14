<a name="top"></a>
# [⬅️ Back to UTILS Documentation](./README.md)

# clean_exit

Declaration:
```c
int clean_exit(t_data *d, int code);
```

Purpose:

Releases loaded textures, image, and window, then exits the program.

Parameters:

`d` - global context with MLX handles.

`code` - process exit code passed to `exit(code)`.

Notes:

- destroys all loaded texture images in a loop
- destroys main render image
- destroys window
- terminates process

---
[⬆️ Back to Top](#top)
