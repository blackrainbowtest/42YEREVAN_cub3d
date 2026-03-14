<a name="top"></a>
# [⬅️ Back to HOOK Documentation](./README.md)

# on_keydown

Declaration:
```c
int on_keydown(int keycode, void *param);
```

Summary:

Handles key press events by updating movement/rotation flags.

Parameters:

`keycode` - pressed key code from MLX.

`param` - pointer to global context (`t_data *`).

Return value:

Returns `0`.

Flow:

1. Cast `param` to `t_data *`.
2. If `KEY_ESC`, call `clean_exit(...)`.
3. Set pressed-state flags:
   `forward`, `backward`, `strafe_left`, `strafe_right`, `turn_left`, `turn_right`.

Notes:

This function updates input state only. Movement is applied later by
`player_update(...)` during frame rendering.

---
[⬆️ Back to Top](#top)