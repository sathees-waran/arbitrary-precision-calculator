# Arbitrary Precision Calculator (APC)

## Overview

The Arbitrary Precision Calculator (APC) is a Data Structures and Algorithms (DSA) project developed in C to perform arithmetic operations on large integer values using a doubly linked list.

Each digit of an operand is stored in a separate node, allowing the program to perform arithmetic operations through linked-list traversal and manipulation rather than relying on built-in integer arithmetic for the operands.

The calculator supports addition, subtraction, multiplication, and division. The program accepts operands and an operator through command-line arguments and displays the calculated result.

## Features

- Addition of large integers with carry handling.
- Subtraction of large integers with borrow handling and negative-result detection.
- Multiplication using digit-by-digit multiplication, partial products, and addition.
- Division using repeated subtraction and comparison to calculate the quotient.
- Doubly linked list representation of operands and results.
- Input validation for non-digit characters in operands.
- Leading-zero removal to maintain a normalized number representation.
- Dynamic memory allocation and linked-list memory management.
- Modular implementation with separate functions for arithmetic operations.

## Project Structure

| File | Description |
|---|---|
| `main.c` | Entry point of the program. Validates the number of command-line arguments, identifies the requested arithmetic operator, invokes the corresponding operation, and displays the result. |
| `apc.h` | Header file containing the `Dlist` structure definition, status macros, and function prototypes shared across the project. |
| `apc.c` | Implements common linked-list utilities, including digit-to-list conversion, node insertion, number comparison, list printing, leading-zero removal, and memory deallocation. |
| `addition.c` | Implements digit-by-digit addition by traversing the operands from their tails and handling carry values. |
| `subtraction.c` | Implements subtraction by comparing operands, processing digits from right to left, handling borrow values, and identifying negative results. |
| `multiplication.c` | Implements digit-by-digit multiplication using partial products, positional zero shifting, and the addition function to combine intermediate results. |
| `division.c` | Implements integer division using repeated subtraction. It compares the current remainder with the divisor and repeatedly subtracts the divisor to determine the quotient. |

## Technologies and Concepts

### Technologies

- **Programming Language:** C
- **Data Structure:** Doubly Linked List
- **Compiler:** GCC
- **Version Control:** Git
- **Code Hosting:** GitHub

### Data Structures and Algorithms

- Doubly linked list creation and traversal.
- Insertion at the beginning and end of a linked list.
- Comparison of large integer representations.
- Digit-by-digit arithmetic algorithms.
- Carry and borrow propagation.
- Partial-product generation for multiplication.
- Repeated-subtraction algorithm for division.
- Leading-zero normalization.

## Skills Applied

- **C Programming:** Functions, pointers, structures, header files, conditional statements, and loops.
- **Dynamic Memory Management:** Allocating nodes using `malloc()` and releasing memory using `free()`.
- **Pointer Manipulation:** Managing head and tail pointers and maintaining `prev` and `next` links.
- **Modular Programming:** Separating arithmetic operations and common utilities into individual source files.
- **Input Validation:** Checking command-line arguments and validating numeric operands.
- **Algorithm Development:** Implementing arithmetic operations using linked-list-based digit processing.
- **Debugging and Testing:** Compiling the program and testing arithmetic operations with different input values.
- **Version Control:** Tracking source code and maintaining the project in a GitHub repository.

## Compilation

Make sure GCC is installed and available in your system's PATH.

Compile all source files from the project directory:

```bash
gcc main.c apc.c addition.c subtraction.c multiplication.c division.c -o apc
```

## Usage

Run the executable with two integer operands and an arithmetic operator.

### Syntax

```bash
./apc <number1> <operator> <number2>
```

### Examples

**Addition**

```bash
./apc 12345678901234567890 + 98765432109876543210
```

**Subtraction**

```bash
./apc 10000000000000000000 - 123456789
```

**Multiplication**

```bash
./apc 12345678901234567890 x 25
```

**Division**

```bash
./apc 1000 / 25
```

The supported operators are `+`, `-`, `x`, and `/`. Use `x` for multiplication rather than `*`.

## Learning Outcomes

Through this project, I gained practical experience in representing large numbers using doubly linked lists and implementing arithmetic algorithms through pointer-based operations.

The project strengthened my understanding of dynamic memory allocation, linked-list manipulation, modular C programming, algorithm design, and command-line argument handling.

## Author

**Satheeswaran M**

Electronics and Communication Engineering

## License

This project is available for educational and learning purposes.
