<a name="top"></a>
# [⬅️ Back to API Documentation](../README.md)

# Hooks API

This section describes input and window event hooks used by the engine.

## Functions

| function name | Declaration | Description |
|--------|--------|--------|
| [on_keydown](on_keydown.md) | ```int	on_keydown(int keycode, void *param)``` | handles key press and sets input state flags |
| [on_keyup](on_keyup.md) | ```int	on_keyup(int keycode, void *param)``` | handles key release and clears input state flags |
| [on_destroy](on_destroy.md) | ```int	on_destroy(void *param)``` | handles window close and exits via cleanup path |

[⬆️ Back to Top](#top)