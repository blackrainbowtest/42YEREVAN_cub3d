<a name="top"></a>
# [⬅️ Back to RAYCAST Documentation](./README.md)

# raycast_dda

Declaration:
```c
void raycast_dda(t_data *d, double dir_x, double dir_y, t_dda *r);
```

Purpose:

Runs one complete DDA raycast for a single ray direction.

Parameters:

`d` - global engine context.

`dir_x`, `dir_y` - ray direction vector.

`r` - output DDA state/result.

Logic:

This function is a wrapper around two steps:

1. `init_dda(...)`
2. `cast_dda(...)`

After it returns, `r` contains hit side, map cell and hit distance.

---
[⬆️ Back to Top](#top)
