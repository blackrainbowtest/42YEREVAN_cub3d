<a name="top"></a>
# [⬅️ Back to MINIMAP Documentation](./README.md)

# draw_tile_with_border

Declaration:
```c
void draw_tile_with_border(t_data *d, int x, int y, int fill_color);
```

Purpose:

Draws one minimap tile with a border.

Behavior:

- border pixels use `MAP_COLOR_GRID`
- inner pixels use `fill_color`

This improves minimap readability.

---
[⬆️ Back to Top](#top)
