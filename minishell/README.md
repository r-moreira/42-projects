## 🚀 Minishell
The objective of this project is to create a simple shell.
---

## 📖 Subject
There is a PDF in the subject folder containing details about the project.

---

## 🖥️ Running the project

```bash
# Install readline library
sudo-apt-get install libreadline6-dev

# Clone the repository
git clone https://github.com/r-moreira/42-projects.git

# Enter the project directory
cd minishell/

# Run
make
```

---

## ✔️ Features
* Prompt
* Working History
* Search executables based on PATH variable ou absolute path
* Built-ins (echo, cd, pwd, export, unset, env, exit)
* Single and Double Quotes
* Redirections:
  * '<' redirect input.
  * '>' redirect output
  * '<<' here document
  * '>>' redirect output with append mode
* Pipes
* Environment variables
* '$?'
* Signal handling with ctrl-C, ctrl-D and ctrl-\
> See the subject for more details
---

## 🖥 Preview
<p>
  <img src="./img/minishell-img.png" width="600">
</p>
