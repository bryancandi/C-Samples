# macro processor

- `main.c` — main function; reads and processes input
- `macro.c` — hash table operations: `hash`, `lookup`, `install`, `undef`
- `macro.h` — header for the hash table and macro system
- `getword.c` — input utilities: `getword`, `getch`, `ungetch`

Compile with:

```sh
gcc -Wall -Wextra -Wpedantic main.c macro.c getword.c -o macro
