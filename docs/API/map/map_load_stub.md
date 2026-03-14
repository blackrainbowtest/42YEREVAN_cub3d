<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

# map_load_stub

Declaration:
```c
int map_load_stub(t_map *map);
```

Summary:

Builds a hardcoded development map and initializes player spawn state.


Map layout used:
```c
111111
101001
101E01
100001
111111
```

Legend:

`1` = wall, `0` = floor, spawn marker (`N/S/E/W`) = player start.


Flow:

1. Assign static grid pointer and map dimensions.
2. Set default colors and texture paths.
3. Scan grid for first spawn marker.
4. Place player at tile center (`x + 0.5`, `y + 0.5`).
5. Set initial direction from spawn marker.
6. If no spawn is found, use fallback position/direction.


Return value:

Returns `0`.

---
[⬆️ Back to Top](#top)