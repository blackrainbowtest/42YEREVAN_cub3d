# on_keydown

Declaration:
int on_keydown(int keycode, void *param);

Purpose:
Handles keyboard press events.
This function updates movement state flags when a key is pressed.
It does NOT move the player directly.

Actual movement and rotation are processed later inside the frame update loop.

Parameters:

keycode
Integer key code provided by the MLX event system.
Represents which key was pressed.

Examples:
```bash
KEY_W
KEY_S
KEY_A
KEY_D
KEY_ESC
```
param
Pointer to the main application context.

Expected type:
```bash
t_data *
```
This structure contains:
- map data
- player position
- movement flags
- rendering data

Logic:

1. Cast param to t_data*
2. Check which key was pressed
3. Update the corresponding movement flag

Example:
```bash
if (keycode == KEY_W || keycode == KEY_AR_T)
    d->move.forward = 1;
```
Supported keys:
```bash
KEY_ESC        -> exit application
KEY_W / AR_T   -> move forward
KEY_S / AR_B   -> move backward
KEY_A / AR_L   -> rotate left
KEY_D / AR_R   -> rotate right
```
Important design rule:

Hooks DO NOT execute gameplay logic directly.

They only update movement state flags:
```bash
d->move.forward
d->move.backward
d->move.turn_left
d->move.turn_right
```
These flags are processed later in the frame update loop.