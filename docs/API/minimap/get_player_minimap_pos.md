<a name="top"></a>
# [⬅️ Back to MINIMAP Documentation](./README.md)

# get_player_minimap_pos

Declaration:
```c
void get_player_minimap_pos(t_data *d, int *x, int *y);
```

Purpose:

Converts player world coordinates into minimap pixel coordinates.

Formula:

`x = MINIMAP_X + player_x * MINIMAP_TILE`

`y = MINIMAP_Y + player_y * MINIMAP_TILE`

---
[⬆️ Back to Top](#top)
