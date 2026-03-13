<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

# is_wall

Declaration:
```c
int is_wall(t_map *m, double x, double y);
```
Purpose:

Checks whether a given world coordinate corresponds to a wall tile
in the map grid.

This function is one of the core collision queries used by the engine.
It is used by:

- player movement
- raycasting
- collision detection
- map boundary protection


Parameters:

`m`  
Pointer to the map structure.

Expected type:

`t_map *`

This structure contains:

- grid (char **)
- map width
- map height
- player position
- player direction


`x`  
World X coordinate (double).

`y`  
World Y coordinate (double).

The coordinates are expressed in **map space**, not pixels.


### Logic:

Step 1 — Convert world coordinates to map cell indices.

`mx = (int)x`  
`my = (int)y`

Example:

`x = 3.7  -> mx = 3`  
`y = 2.1  -> my = 2`  

This determines which map tile the coordinate belongs to.


Step 2 — Boundary protection.
```c
if (mx < 0 || my < 0 || my >= m->height || mx >= m->width)
    return (1);
```
If the coordinate is outside the map, the function returns 1.

Outside the map is treated as a wall.


Step 3 — Check the map grid.
```c
return (m->grid[my][mx] == ICN_WALL);
```
If the tile contains a wall character, the function returns true.


### Return value:

`1 -> the tile is a wall`  
`0 -> the tile is empty`


### Design note:

Treating out-of-bounds as walls prevents the player and rays
from escaping the map area.

---
[⬆️ Back to Top](#top)