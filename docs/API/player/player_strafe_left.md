<a name="top"></a>
# [⬅️ Back to PLAYER Documentation](./README.md)

# player_strafe_left

Declaration:
```c
void player_strafe_left(t_data *d);
```

Purpose:

Moves the player left using the vector perpendicular to direction.

Formula used:

`(+dir_y, -dir_x) * MOVE_SPEED`

Collision checks are applied before committing movement.

---
[⬆️ Back to Top](#top)
