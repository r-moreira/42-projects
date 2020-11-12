## 🚀 The second 42 college project!
This projects is about creating a function that reads a line ending with a newline character ('\n') from a file descriptor.
This project use static variables, needs a deeper understanding of allocations and how to use buffers.

---

## 📖 Subject
There is a PDF in the subject folder containing details about the project.

---

## 🖥️ Running Tests

Just a simple test just to see the function being performed.\
Note: The project was developed on MacOS, in other operating systems there may be undefined behaviors.

```bash
# Clone the repository
git clone https://github.com/r-moreira/42-projects.git

# Enter the project directory
cd get_next_line/

# For the standard function without bonus test on stdin run
make stdin -C tests/

# For the standard function without bonus and test on a file run
make file -C tests/

# For the standard function with bonus test on stdin run
make bonus_stdin -C tests/

# For the standard function with bonus and test on a file run
make bonus_file -C tests/
