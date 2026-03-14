<a name="top"></a>
# [⬅️ Back to PLAYER Documentation](./README.md)

# player_strafe_right

Declaration:
```c
void player_strafe_right(t_data *d);
```

Purpose:

Moves the player right using the opposite perpendicular direction.

Formula used:

`(-dir_y, +dir_x) * MOVE_SPEED`

Collision checks are applied before committing movement.

---
[⬆️ Back to Top](#top)
