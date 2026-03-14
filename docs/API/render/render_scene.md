<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# render_scene

Declaration:
```c
void render_scene(t_data *d);
```

Purpose:

Renders the 3D view by casting one ray per screen column.

Logic:

Loops `x` from `0` to `WINDOW_WIDTH - 1` and calls
`render_wall_column(d, x)`.

---
[⬆️ Back to Top](#top)
