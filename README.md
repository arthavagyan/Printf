*This project has been created as part of the 42 curriculum by artavagy.*
# ft_printf

## Description

**`ft_printf`** is a custom implementation of the standard C function `printf`.

This project focuses on understanding:
- variadic functions (`va_list`)
- formatted output
- parsing and handling flags
- width and precision
- type conversions

The goal is to recreate the behavior of the original `printf`, including its formatting rules and edge cases.

---

## The Goal of the Project

The main objectives of this project are:

- Implement a function `ft_printf` that:
  - prints formatted output to the standard output
  - returns the number of printed characters

## Instructions

- Support mandatory conversion specifiers:
  - `%c` — character
  - `%s` — string
  - `%p` — pointer
  - `%d` / `%i` — signed integer
  - `%u` — unsigned integer
  - `%x` / `%X` — hexadecimal
  - `%%` — percent sign

- Implement bonus features:
  - Flags:
    - `-` (left alignment)
    - `0` (zero padding)
    - `.` (precision)
    - `#` (alternative form for %x and %X)
    - `+` (force sign)
    - ` ` (space)
  - Width handling
  - Precision handling

To compile, run:

- make

Is compiled using the provided Makefile and the `cc` compiler with the following flags:
 
 - -Wall -Wextra -Werror


This will generate the static library file `libftprintf.a` at the root of the repository.

### Makefile rules

- make / make all  : To compile the library
- make clean  : Remove object files
- make fclean  : Remove object files and the library
- make re : Recompile everything

## Resources 

- Linux manual pages (man 3)
- GNU C Library documentation
- W3Schools.com
- 42 intranet Libft subject
- Google search resources
- Peer on the right peer on the left and someone smart in the building
