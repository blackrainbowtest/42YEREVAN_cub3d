<a name="top"></a>
# [⬅️ Back to HOOK Documentation](./README.md)

# on_destroy

Declaration:
```c
int on_destroy(void *param);
```

Summary:

Handles window close events and exits through unified cleanup.

Parameters:

`param` - pointer to global context (`t_data *`).

Return value:

Returns the result of `clean_exit(d, 0)`.

Flow:

1. Cast `param` to `t_data *`.
2. Call cleanup/exit routine.

Notes:

Makes window-close behavior consistent with ESC exit path.

---
[⬆️ Back to Top](#top)