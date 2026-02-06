*This project has been created as part of the 42 curriculum by <heychong>.*

# PUSH_SWAP

## Description

The **push_swap** project focuses on sorting a list of integers using two stacks and a restricted set of operations.
The goal is to output the smallest possible sequence of valid instructions that sorts the initial stack in ascending order.

The program takes a list of integers as input, stores them in stack **A**, and uses stack **B** as auxiliary storage. Only predefined operations such as swap, push, rotate, and reverse rotate are allowed. Direct access to elements or arbitrary swaps are forbidden, which requires the implementation of an efficient sorting strategy under strict constraints.

This project emphasizes algorithmic thinking, data structure manipulation, and complexity optimization, as performance is evaluated based on the number of operations produced for various input sizes.


## Instructions

### Compilation
compile the program using the provided Makefile:
```
make
```

To remove object files:
```
make clean
```

To remove the project:
```
make fclean
```

To recompile the project:
```
make re
```

### Execution
```
./push_swap 4 -67 3 87 23 or ./push_swap "4 -67 3 87 23"
```


## Resources

### Technical References
**IT用語辞典**:
Used to understand new concepts such as stacks, time complexity, and list data structures.

**Qiita**:
Consulted for practical examples of stack operations and sorting algorithms, particularly radix sort implementations.

### Use of AI Assistance

AI was used as a development support tool:

・Detecting typos and inconsistencies in self-written code.

・Pointing out potential logical errors in algorithms and stack operations.

・Discussing identified issues to deepen understanding and correct the logic.

All core logic and implementation decisions were made by the author, with AI used solely for review and conceptual clarification.
