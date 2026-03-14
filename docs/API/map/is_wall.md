<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

# is_wall

Declaration:
```c
int is_wall(t_map *m, double x, double y);
```
Summary:

Checks whether world coordinates map to a wall tile.


Parameters:

`m` - map structure.

`x` - world X coordinate (map-space units).

`y` - world Y coordinate (map-space units).


Flow:

1. Convert world coordinates to integer cell indices.
2. Treat out-of-bounds as walls.
3. Return whether grid cell equals `ICN_WALL`.

Boundary rule:
```c
if (mx < 0 || my < 0 || my >= m->height || mx >= m->width)
    return (1);
```

Return value:

`1` for wall or out-of-bounds, `0` for non-wall cell.

Notes:

Out-of-bounds as wall prevents leaving map limits.

---
[⬆️ Back to Top](#top)