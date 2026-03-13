<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# MAPs API

This section describes input and window event hooks used by the engine.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [is_wall](is_wall.md) | ```int	is_wall(t_map *m, double x, double y)``` | checks whether a given world coordinate corresponds to a wall tile in the map grid. |
| [is_spawn_char](internal.md#is_spawn_char) | ```static int	is_spawn_char(char c)``` | updates movement state when a key is released |
| [set_player_dir](internal.md#set_player_dir) | ```static void	set_player_dir(t_map *map, char spawn)``` | updates movement state when a key is released |
| [map_load_stub](map_load_stub.md) | ```int	map_load_stub(t_map *map)``` | closes the application when the window is destroyed |

[⬆️ Back to Top](#top)