<a name="top"></a>
# [⬅️ Back to HOOK Documentation](./README.md)

# on_keyup

Declaration:
```c
int on_keyup(int keycode, void *param);
```

Summary:

Handles key release events by clearing movement/rotation flags.

Parameters:

`keycode` - released key code from MLX.

`param` - pointer to global context (`t_data *`).

Return value:

Returns `0`.

Flow:

1. Cast `param` to `t_data *`.
2. Reset released-key state flags:
   `forward`, `backward`, `strafe_left`, `strafe_right`, `turn_left`, `turn_right`.

Notes:

Without this handler, movement flags can remain set after key release.

---
[⬆️ Back to Top](#top)