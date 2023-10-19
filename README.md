# MONTY

## Stack and Queue
- Stack is a container of objects that are inserted and removed according to the last-in first-out (LIFO) principle. Queue is a container of objects (a linear collection) that are inserted and removed according to the first-in first-out (FIFO) principle.

## The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

## General
- All files compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=c89
- Code style: the ```Betty style```. Checked using ```betty-style.pl``` and ```betty-doc.pl```.
- No more than 5 functions per file.
- Uses the C standard library.
- The prototypes of all functions included in header file called ```monty.h```.

## Compilation & Output
- Code will be compiled this way:
```$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty```
- Output printed on: ```stdout```.
- Error messages printed on ```stderr```.

## Tasks
- 0. Push, Pall: ```push``` and ```pall``` opcodes
	- ***The Push Opcode*** : Pushes an element to the stack
	- ***The Pall Opcode*** : Prints all the values on the stack, starting from the top of the stack.


#### Authors
- Yvonne Gachara: https://github.com/Vonleo
- Kennedy Simiyu: https://github.com/Kennie-Simz
