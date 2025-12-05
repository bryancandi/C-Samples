# \#define macro processor (K&R exercise 6-6)

This simple #define processor program stores macros in a hash table of linked lists. It currently supports `#define` and `#undef` to insert or remove entries from the table.

- `main.c` — main function; reads and processes input
- `macro.c` — hash table operations: `hash`, `lookup`, `install`, `undef`
- `macro.h` — header for the hash table and macro system
- `getword.c` — input utilities: `getword`, `getch`, `ungetch`

Compile with:

```sh
gcc -Wall -Wextra -Wpedantic main.c macro.c getword.c -o macro
