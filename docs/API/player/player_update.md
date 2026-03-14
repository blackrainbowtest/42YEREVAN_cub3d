<a name="top"></a>
# [⬅️ Back to PLAYER Documentation](./README.md)

# player_update

Declaration:
```c
void player_update(t_data *d);
```

Purpose:

Applies movement and rotation flags for one frame.

Logic:

- checks each input flag in `d->move`
- calls corresponding movement/rotation function
- refreshes camera plane via `camera_init(&d->map)`

This is the central per-frame input executor.

---
[⬆️ Back to Top](#top)
