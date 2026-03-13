<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

# map_load_stub

Declaration:
```c
int map_load_stub(t_map *map);
```

Purpose:

Creates a temporary hardcoded map used during early development
before implementing the real map parser.

This function allows testing:

- rendering
- raycasting
- player movement
- minimap


Map layout used:
```c
111111
101001
101E01
100001
111111
```

Explanation:

`1 = wall`  
`0 = empty floor`  
`E = player spawn position`  


Initialization Steps:

1. Assign grid pointer

`map->grid = grid;`  


2. Set map dimensions

`map->width = 6`  
`map->height = 5`


3. Search for player spawn

The function scans the grid to find a spawn character:

`N`  
`S`  
`E`  
`W`  


### When a spawn is found:

`map->player_x = x + 0.5`  
`map->player_y = y + 0.5`


### Why +0.5?

This places the player at the **center of the tile**
instead of the top-left corner.


4. Set player direction

The spawn character determines the initial facing direction.

Example:

`E -> dir_x = 1`  
     `dir_y = 0`


5. Fallback spawn

If no spawn character is found, a default position is used:

`player_x = 3`  
`player_y = 3`  

`dir_x = 0`  
`dir_y = -1`  


### Return value:

Returns `0` on success.

---
[⬆️ Back to Top](#top)