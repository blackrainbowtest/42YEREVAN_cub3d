<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# render_wall_column

Declaration:
```c
void render_wall_column(t_data *d, int x);
```

Purpose:

Builds the ray for one screen column, runs DDA, then draws that wall column.

Core math:

`camera_x = 2.0 * x / WINDOW_WIDTH - 1.0`

`ray_dir = dir + plane * camera_x`

---
[⬆️ Back to Top](#top)
