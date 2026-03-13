<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

## INTERNAL STATIC FUNCTIONS

These functions are internal helpers and are not part of the public API.
However they are documented for completeness.


------------------------------------------------------------

## is_spawn_char

Declaration:
```c
static int is_spawn_char(char c);
```

Purpose:

Checks whether a character represents a valid player spawn marker.


Supported spawn characters:

`N -> North`  
`S -> South`  
`E -> East`  
`W -> West`  


Return value:

`1 -> valid spawn character`  
`0 -> not a spawn character`


Example:
```c
if (is_spawn_char(grid[y][x]))
    ...
```
------------------------------------------------------------

## set_player_dir

Declaration:
```c
static void set_player_dir(t_map *map, char spawn);
```

Purpose:

Sets the player's initial direction vector based on the spawn character.


Direction vectors:

`N -> (0, -1)`  
`S -> (0, 1)`  
`E -> (1, 0)`  
`W -> (-1, 0)`  


Explanation:

The direction vector represents the direction the player is facing
in map space.

Example:

`dir_x = 1`  
`dir_y = 0`  

means the player is looking east.


Design note:

Using direction vectors instead of angles simplifies movement and
raycasting calculations.

---
[⬆️ Back to Top](#top)