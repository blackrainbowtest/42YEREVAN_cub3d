<a name="top"></a>
# [⬅️ Back to RENDER Documentation](./README.md)

# draw_wall_column

Declaration:
```c
void draw_wall_column(t_data *d, int x, t_dda *r);
```

Purpose:

Transforms ray hit distance into projected wall height on screen.

Logic:

- `line_height = WINDOW_HEIGHT / dist`
- computes `draw_start` and `draw_end` around screen center
- clamps both to visible range
- delegates pixel fill to `draw_column_pixels(...)`

---
[⬆️ Back to Top](#top)
