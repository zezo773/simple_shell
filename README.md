<p align="center">
  <img src="https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg" alt="Holberton School logo">
</p>

# Eshell - A Simple UNIX Command Line Interpreter

Eshell is a basic UNIX shell implemented in C. It provides a prompt where users can enter commands, and the shell will execute them just like traditional shells (e.g., `sh`, `bash`).

---

## Features

- Custom shell prompt: `(Eshell) $`
- Tokenizes and parses user input.
- Locates and executes system commands from the `$PATH`.
- Handles basic command execution using `fork()`, `execve()`, and `waitpid()`.
- Gracefully handles command not found errors.
- Clean memory management.

---

## Files

| File          | Description                                                  |
|---------------|--------------------------------------------------------------|
| `main.c`      | Main shell loop: reads input, parses it, and runs commands.  |
| `execmd.c`    | Handles forking and executing user commands.                 |
| `get_location.c` | Finds the full path of commands based on the `$PATH`.     |
| `main.h`      | Header file containing function prototypes and includes.     |

---

## How It Works

1. The shell prints a prompt: `(Eshell) $`
2. It waits for the user to type a command.
3. The input is tokenized into the command and its arguments.
4. The shell locates the executable using the `PATH` environment variable.
5. A child process is forked to execute the command using `execve()`.
6. The parent shell waits for the child to finish before accepting the next command.

---

## Compilation

Use `gcc` to compile all the source files:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o eshell
