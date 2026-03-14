<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# Player API

This section documents movement, rotation and per-frame input processing.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [player_move_forward](player_move_forward.md) | ```void player_move_forward(t_data *d)``` | moves player forward with collision checks |
| [player_move_backward](player_move_backward.md) | ```void player_move_backward(t_data *d)``` | moves player backward with collision checks |
| [player_strafe_left](player_strafe_left.md) | ```void player_strafe_left(t_data *d)``` | strafes player left relative to direction |
| [player_strafe_right](player_strafe_right.md) | ```void player_strafe_right(t_data *d)``` | strafes player right relative to direction |
| [player_rotate](player_rotate.md) | ```void player_rotate(t_data *d, double angle)``` | rotates direction and camera plane |
| [player_update](player_update.md) | ```void player_update(t_data *d)``` | applies movement flags each frame |

[⬆️ Back to Top](#top)
