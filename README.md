# Simple Shell

This is a `simple shell` program written in C. It provides a basic command-line interface that allows you to execute commands.

## Table of Contents
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)

## Features

- Basic shell functionality
- Command execution
- Environment variable display

## Getting Started

### Prerequisites

- You need a C compiler, such as `GCC`, to build the shell program.

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/DevBasem/simple_shell.git
   ```
   
2. Compile the program

   ```bash
   gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
   ```
   
## Usage

- To run the shell, execute the compiled binary:
   ```bash
   ./hsh
   ```
## Commands

### Supported Commands

- `exit`: Exit the shell.
- `env`: Display the environment variables.

##Examples

1. Execute a command:
    ```bash
    $ ls
    ```
2. Exit the shell:
    ```bash
    $ exit
    ```
3. Display environment variables:
    ```bash
    $ env
    ```
