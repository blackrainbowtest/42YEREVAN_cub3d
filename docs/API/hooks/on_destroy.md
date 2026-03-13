<a name="top"></a>
# [⬅️ Back to HOOK Documentation](./README.md)

# on_destroy

Declaration:
int on_destroy(void *param);

Purpose:
Handles window destroy events.

Triggered when the user closes the application window.

Examples:
clicking the window close button.

Parameters:

param
Pointer to the main application context.

Expected type:
```bash
t_data *
```
Logic:

The function casts the parameter to t_data* and calls:
```bash
clean_exit(d, 0);
```
This ensures the program exits through the normal cleanup procedure.

Why this is necessary:

Closing the window should perform the same cleanup as pressing ESC.

Centralizing shutdown logic inside clean_exit() prevents duplicated code
and ensures all resources are released correctly.

---
[⬆️ Back to Top](#top)