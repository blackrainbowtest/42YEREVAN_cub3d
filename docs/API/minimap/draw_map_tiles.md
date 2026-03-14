<a name="top"></a>
# [⬅️ Back to MINIMAP Documentation](./README.md)

# draw_map_tiles

Declaration:
```c
void draw_map_tiles(t_data *d);
```

Purpose:

Iterates over the map grid and draws each tile at minimap coordinates.

Behavior:

- wall cells use wall color
- non-wall cells use background color
- each tile is drawn with border via `draw_tile_with_border(...)`

---
[⬆️ Back to Top](#top)
