<a name="top"></a>
# [⬅️ Back to PLAYER Documentation](./README.md)

# player_move_forward

Declaration:
```c
void player_move_forward(t_data *d);
```

Purpose:

Moves the player forward along the direction vector with collision checks.

Key behavior:

- computes next position using `MOVE_SPEED`
- checks collisions with player radius
- applies X and Y movement separately to avoid corner locking

---
[⬆️ Back to Top](#top)
