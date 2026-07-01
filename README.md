# 🖨️ ft_printf — A custom printf implementation

<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100" />
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C" />
  <img src="https://img.shields.io/badge/Status-Completed-brightgreen?style=for-the-badge" alt="Status Completed" />
</p>

---

## 📖 Description

**ft_printf** is a project at **42 School**. The goal is to recreate the famous `printf` function from the standard C library. 

This project is a great way to learn about **Variadic Functions** in C and how to handle different data types. It is an important step in building a personal C library.

---

## 🎯 Project Goals

- Learn how to use `va_list`, `va_start`, `va_arg`, and `va_end`.
- Practice parsing strings to find format specifiers.
- Handle different types of output (numbers, strings, addresses).
- Manage complex flags and formatting.

---

## ✨ Supported Conversions

The function handles the following format specifiers:

| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single **character**. |
| `%s` | Prints a **string** (as defined by the common C convention). |
| `%p` | Prints the **void * pointer** argument in hexadecimal format. |
| `%d` | Prints a **decimal** (base 10) number. |
| `%i` | Prints an **integer** in base 10. |
| `%u` | Prints an **unsigned decimal** (base 10) number. |
| `%x` | Prints a number in **hexadecimal** (base 16) lowercase format. |
| `%X` | Prints a number in **hexadecimal** (base 16) uppercase format. |
| `%%` | Prints a **percent sign**. |

---

## 🌟 Bonus Features

My version also supports these advanced flags:

*   **Field Width:** Sets the minimum width for the output.
*   **Precision:** Handles the `.` flag for numbers and strings.
*   **Flags:**
    *   `-` Left-justify the output.
    *   `0` Use zero-padding instead of spaces.
    *   `#` Add a prefix to hexadecimal numbers (`0x` or `0X`).
    *   `+` Always show the sign (+ or -) for numbers.
    *   `(space)` Print a space before positive numbers.

---

## 🛠️ How to Use

### 1. Compilation
To build the library, simply run the command below:

```bash
make
```
After running this, you will see a file named `libftprintf.a`.

### 2. Integration
To use **ft_printf** in your code, include the header file and link the library during compilation:

```c
#include "ft_printf.h"

int main() 
{
    ft_printf("Hello %s, the number is %d\n", "World", 42);
    return (0);
}
```

**Example compilation command:**
```bash
cc main.c libftprintf.a -o my_program
```

### 3. Makefile Rules

| Rule | Action |
| :--- | :--- |
| **make** | Compiles the library. |
| **make clean** | Deletes object files. |
| **make fclean** | Deletes object files and `libftprintf.a`. |
| **make re** | Re-compiles the entire project. |

---

## 👨‍💻 Author

This project was created by **artavagy** as part of the 42 curriculum.

<div align="center">

  [![GitHub Profile](https://img.shields.io/badge/GitHub-artavagy-181717?style=for-the-badge&logo=github)](https://github.com/arthavagyan)

</div>

