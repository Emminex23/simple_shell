# Simple Shell - 0x16. C
![gates_of_shell](https://github.com/Emminex23/simple_shell/assets/77441838/078e26b2-adf9-4878-bf9f-8cffeca582f3)

A UNIX command interpreter implemented in C as part of ALX School's low-level programming projects. This project is a detailed introduction to the basics of C programming, thinking like an engineer, group work, and importantly, learning how to learn.

## Table of Contents
- [Background](#background)
- [Learning Objectives](#learning-objectives)
- [Installation](#installation)
- [Usage](#usage)
- [Testing](#testing)
- [Contributing](#contributing)
- [Authors](#authors)
- [License](#license)

## Background

This project aims to replicate the functioning of a simple UNIX shell, such as sh. The journey includes manipulating the environment of a process, working with system calls, and creating processes.

## Learning Objectives
At the end of this project, learners should understand:

- The design and implementation of the original Unix operating system.
- The functioning of a shell.
- The differences between functions and system calls.
- How to execute another program with the execve system call.
- The importance of PID and PPID.

## Installation

1. Clone the repository:
```
git clone https://github.com/your_github_username/simple_shell.git
```
2. Navigate to the project directory:
```
cd simple_shell
```
3. Compile with:
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
## Usage
Run the shell in interactive mode with:
```
./hsh
```
Or use it in non-interactive mode:
```
echo "/bin/ls" | ./hsh
```
## Testing
Your shell can be tested using provided checks, including those in the test_ls_2 file:
```
cat test_ls_2 | ./hsh
```
## Contributing
This project is part of a curriculum and as such doesn't accept contributions. However, feedback is welcome.

## Authors
- Emmanuel Oyibo
- [Lauren Bello Alvarez](https://github.com/lauren-belloalvarez)

Refer to the AUTHORS file for more details.

## License
This project is licensed under the ALX School student policy.
