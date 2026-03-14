<a name="top"></a>
# [⬅️ Back to LOADER Documentation](./README.md)

# load_texture

Declaration:
```c
int load_texture(t_data *d, t_tex *tex, char *path);
```

Purpose:

Loads one XPM file into an MLX image and initializes texture buffer fields.

Parameters:

`d` - MLX context owner.

`tex` - destination texture structure.

`path` - path to the XPM file.

Return value:

`0` on success, `ERROR` on failure.

Logic:

1. `mlx_xpm_file_to_image(...)` creates image and sets width/height.
2. `mlx_get_data_addr(...)` retrieves pixel address and format metadata.

---
[⬆️ Back to Top](#top)
