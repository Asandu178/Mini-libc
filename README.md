# Mini-libc

## Overview

This project was originally developed as a homework assignment for the Operating Systems course. I decided to make the repository public to showcase some of the concepts I worked with, particularly low-level programming and the Linux system call interface.

The goal of the assignment was to implement a minimal version of the standard C library for Linux on x86-64, without relying on external library calls.

## Implementation

Working on this project helped me understand several concepts related to low-level programming and how the C standard library works, such as:

- Implementing string manipulation and memory functions, including `memcpy()`, `memmove()`, `strlen()`, and `strcmp()`.
- Interacting directly with the Linux system call interface to implement file I/O operations.
- Implementing memory management functions such as `malloc()`, `free()`, `calloc()`, and `realloc()`.
- Working with memory mapping through system calls such as `mmap()`, `mremap()`, and `munmap()`.
- Handling errors and setting `errno` appropriately when operations fail.
- Implementing basic I/O and time-related functions such as `puts()`, `nanosleep()`, and `sleep()`.

This assignment gave me practical experience with low-level memory management, system calls, and some of the functionality normally provided by the C standard library.