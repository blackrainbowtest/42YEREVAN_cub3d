<a name="top"></a>
# [⬅️ Back to MAP Documentation](./README.md)

## INTERNAL STATIC FUNCTIONS

These helpers are internal to `map_stub.c` and documented for completeness.

---

## is_spawn_char

Declaration:
```c
static int is_spawn_char(char c);
```

Summary:

Checks whether a map character is one of the allowed spawn markers.

Parameters:

`c` - map cell character.

Return value:

`1` if `c` is one of `N`, `S`, `E`, `W`; otherwise `0`.

---

## set_player_dir

Declaration:
```c
static void set_player_dir(t_map *map, char spawn);
```

Summary:

Sets player direction vector from spawn marker.

Parameters:

`map` - map/game context.

`spawn` - one of `N`, `S`, `E`, `W`.

Flow:

1. Check spawn character.
2. Assign matching `(dir_x, dir_y)` unit vector.

Notes:

Direction vectors are later used by movement and raycasting.

---
[⬆️ Back to Top](#top)