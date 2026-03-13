<a name="top"></a>
# [⬅️ Back to HOOK Documentation](./README.md)

# on_keyup

Declaration:
int on_keyup(int keycode, void *param);

Purpose:
Handles keyboard release events.

This function disables movement flags when the corresponding key is released.

Parameters:

keycode
Integer key code provided by MLX indicating which key was released.

param
Pointer to the main application context.

Expected type:
```bash
t_data *
```
Logic:

When a key is released the corresponding movement flag is reset.

Example:
```bash
if (keycode == KEY_W || keycode == KEY_AR_T)
    d->move.forward = 0;
```
Supported keys:
```bash
KEY_W / AR_T -> stop moving forward
KEY_S / AR_B -> stop moving backward
KEY_A / AR_L -> stop rotating left
KEY_D / AR_R -> stop rotating right
```
Why this is necessary:

Movement is controlled by state flags.

Without on_keyup:

press W -> forward = 1
release W -> forward still = 1
player never stops moving

The key release event ensures correct input state management.

---
[⬆️ Back to Top](#top)