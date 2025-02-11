# Minishell - Your Own Little Bash
# <img src="https://github.com/TeomanDeniz/TeomanDeniz/blob/main/images/repo_projects/125.png" style="width: 75PX;"> Minishell

Welcome to **Minishell**, a project where we built our own simple shell, learnt about **processes, file descriptors, and command execution** along the way.

## 📌 Features
- 🖥 **Interactive command prompt**
- 📜 **Command history support**
- 🛠 **Pipes and redirections**
- 🌍 **Environment variable handling**
- 🔀 **Built-in commands** (`cd`, `echo`, `pwd`, `export`, `unset`, `env`, `exit`)
- 🛡 **Signal handling** (`ctrl-C`, `ctrl-D`, `ctrl-\` behaviors)
- 🚀 **Bonus**: Logical operators (`&&`, `||`) and wildcard expansion (`*`)

---
## 📂 Project Structure
```plaintext
├── src/          # Source files
├── includes/     # Header files
├── libft/        # Custom library (if applicable)
├── Makefile      # Compilation script
└── README.md     # Project documentation
```
---
## ⚡ Installation & Execution
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/minishell.git
   cd minishell
   ```
2. Compile the project:
   ```sh
   make
   ```
3. Run Minishell:
   ```sh
   ./minishell
   ```

---
## 🛠 Functions Overview
| Function Name  | Description |
|--------------|-------------|
| `init_shell()` | Initializes shell environment. |
| `read_input()` | Reads user input using `readline()`. |
| `parse_command()` | Tokenizes input into arguments and operators. |
| `execute_builtin()` | Executes built-in shell commands. |
| `handle_pipes()` | Manages command execution with pipes. |
| `redirect_io()` | Implements input/output redirection. |
| `cleanup_resources()` | Frees memory before exiting. |

---
## 🖥 Shell Features
1. **Command Execution**
   - Runs system commands using `execve()`.
   - Searches for executables based on the `PATH` variable.
2. **Redirections**
   - `<` Redirects input.
   - `>` Redirects output.
   - `>>` Appends output.
   - `<<` Here-document input.
3. **Pipelines (`|`)**
   - Connects multiple commands.
4. **Environment Variable Expansion (`$VAR`)**
   - Supports standard shell variable expansion.
5. **Exit Status (`$?`)**
   - Stores exit status of the last executed command.
6. **Signal Handling**
   - `ctrl-C`: Displays a new prompt.
   - `ctrl-D`: Exits the shell.
   - `ctrl-\`: Does nothing.
7. **Built-in Commands**
   - `echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`

---
## 🎨 Bonus Features
- **Logical Operators (`&&`, `||`)**
- **Wildcard Expansion (`*`)**
- **Parenthesis Handling for Priorities**

---
## 📢 Contributions
Contributions are welcome! Feel free to submit issues or pull requests.

---
## 📄 License
This project is licensed under the **MIT License**.

💻 *Happy coding and enjoy building your own shell!*
