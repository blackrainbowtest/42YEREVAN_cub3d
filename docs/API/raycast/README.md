<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# Raycast API

This section documents DDA raycasting setup and wall hit traversal.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [raycast_dda](raycast_dda.md) | ```void raycast_dda(t_data *d, double dir_x, double dir_y, t_dda *r)``` | high-level raycast wrapper (init + cast) |
| [init_dda](init_dda.md) | ```void init_dda(t_data *d, double dir_x, double dir_y, t_dda *r)``` | initializes DDA state for one ray |
| [cast_dda](cast_dda.md) | ```void cast_dda(t_data *d, t_dda *r)``` | steps through the map until wall hit or max distance |

[⬆️ Back to Top](#top)
