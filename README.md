# libft

A custom C library implementing standard library functions and additional utilities, created as part of the 42 School curriculum.

## Overview

This library provides reimplementations of essential C standard library functions along with additional utility functions for string manipulation, memory management, and linked list operations. All functions are implemented from scratch without using the original C library functions.

## Features

### Character Operations

- **Classification**: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- **Case conversion**: `ft_toupper`, `ft_tolower`

### String Functions

- **Basic operations**: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`
- **String creation**: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strdup`
- **String copying**: `ft_strlcpy`, `ft_strlcat`
- **Function mapping**: `ft_strmapi`, `ft_striteri`

### Memory Management

- **Memory operations**: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
- **Memory searching**: `ft_memchr`, `ft_memcmp`
- **Memory allocation**: `ft_calloc`

### Conversion Functions

- **String to number**: `ft_atoi`
- **Number to string**: `ft_itoa`

### Input/Output

- **File descriptor output**: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`

### Data Structures

Complete singly linked list implementation:

- **Creation**: `ft_lstnew`
- **Insertion**: `ft_lstadd_front`, `ft_lstadd_back`
- **Navigation**: `ft_lstsize`, `ft_lstlast`
- **Deletion**: `ft_lstdelone`, `ft_lstclear`
- **Iteration**: `ft_lstiter`, `ft_lstmap`

## Building

### Basic library (mandatory functions)

```bash
make
```

### With bonus functions

```bash
make bonus
```

### Cleaning

```bash
make clean      # Remove object files
make fclean     # Remove object files and library
make re         # Rebuild from scratch
```

## Usage

1. Include the header in your C files:

```c
#include "libft.h"
```

2. Compile with the library:

```bash
cc your_program.c -L. -lft -o your_program
```

## Function Documentation

All functions are thoroughly documented in `libft.h` with:

- Parameter descriptions
- Return value specifications
- Usage examples where applicable
- Edge case handling notes

## Standards Compliance

- Written in C following the 42 School Norm
- Compiled with `-Wall -Wextra -Werror` flags
- No memory leaks or undefined behavior
- Proper error handling for edge cases

## Author

**mnussler** - 42 Berlin School student

- Email: mnussler@student.42berlin.de
