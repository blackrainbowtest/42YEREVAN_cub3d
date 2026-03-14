<a name="top"></a>
# [⬅️ Back to RAYCAST Documentation](./README.md)

# init_dda

Declaration:
```c
void init_dda(t_data *d, double dir_x, double dir_y, t_dda *r);
```

Purpose:

Initializes all DDA values for the current ray before traversal starts.

Parameters:

`d` - global engine context.

`dir_x`, `dir_y` - ray direction.

`r` - DDA structure to fill.

Initialized fields:

- player position (`pos_x`, `pos_y`)
- ray direction (`dir_x`, `dir_y`)
- current map cell (`map_x`, `map_y`)
- delta distances (`delta_x`, `delta_y`)
- step signs and first side distances (`step_x`, `step_y`, `side_x`, `side_y`)
- current distance (`dist = 0`)

Why this is necessary:

Correct initialization guarantees stable DDA stepping and correct wall hits.

---
[⬆️ Back to Top](#top)
