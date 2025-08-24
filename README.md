# Push Swap

A C implementation of an efficient stack sorting algorithm using a limited set of operations. This project is part of the 42 School curriculum and implements the "Turk Algorithm" for optimal sorting performance.

## Table of Contents

- [Overview](#overview)
- [Algorithm](#algorithm)
- [Operations](#operations)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Project Structure](#project-structure)
- [Requirements](#requirements)
- [Author](#author)

## Overview

Push Swap is a sorting challenge where you must sort a stack of integers in ascending order using only two stacks (A and B) and a limited set of operations. The goal is to achieve this with the minimum number of operations possible.

**Key Features:**
- Efficient sorting using the Turk Algorithm
- Handles stacks of varying sizes (2, 3, or more elements)
- Input validation and error handling
- Optimized cost analysis for operation selection

## Algorithm

The program implements the **Turk Algorithm**, which is highly efficient for this type of constraint-based sorting:

### Algorithm Steps:

1. **Input Validation**: Check for syntax errors, duplicates, and integer overflow
2. **Initial Pushes**: Push nodes from stack A to stack B until only 3 remain in A
3. **Target Assignment**: Each node in A finds its target node in B (closest smaller value)
4. **Cost Analysis**: Calculate the "cheapest" node to move based on required operations
5. **Sort Three**: Sort the remaining 3 elements in stack A
6. **Push Back**: Move all elements from B back to A in correct positions
7. **Final Positioning**: Ensure the minimum element is at the top of stack A

### Cost Calculation Formula:
```
Push Cost = Operations to bring node to top + Operations to bring target to top
```

The algorithm always selects the node with the minimum push cost for the next operation.

## Operations

The following operations are available and will be printed to stdout:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element from stack B to stack A |
| `pb` | Push the top element from stack A to stack B |
| `ra` | Rotate stack A up (first element becomes last) |
| `rb` | Rotate stack B up (first element becomes last) |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A (last element becomes first) |
| `rrb` | Reverse rotate stack B (last element becomes first) |
| `rrr` | Perform `rra` and `rrb` simultaneously |

## Installation

### Prerequisites

This project requires:
- GCC compiler
- Make
- libft library (42 School's custom C library)

### Building

1. Clone the repository:
```bash
git clone <repository-url>
cd push_swap
```

2. Build the project:
```bash
make
```

This will compile the source files and create the `push_swap` executable.

### Make Targets

- `make` or `make all` - Build the project
- `make clean` - Remove object files
- `make fclean` - Remove object files and executable
- `make re` - Clean and rebuild everything

## Usage

The program accepts integers as command-line arguments in two formats:

### Format 1: Multiple arguments
```bash
./push_swap 4 67 3 87 23
```

### Format 2: Single quoted string
```bash
./push_swap "4 67 3 87 23"
```

### Output
The program outputs the sequence of operations needed to sort the stack:
```bash
./push_swap 3 2 1
sa
rra
```

### Error Handling
The program will output "Error" to stderr in the following cases:
- Non-numeric arguments
- Duplicate numbers
- Integer overflow (numbers outside INT_MIN to INT_MAX range)
- Invalid syntax (empty arguments, etc.)

## Examples

### Example 1: Simple 3-element stack
```bash
./push_swap 3 2 1
# Output:
sa
rra
```

### Example 2: Larger stack
```bash
./push_swap 5 4 3 2 1
# Output: (sequence of operations to sort the stack)
pb
pb
sa
pa
pa
```

### Example 3: Already sorted
```bash
./push_swap 1 2 3 4 5
# Output: (no operations - stack is already sorted)
```

### Example 4: Error cases
```bash
./push_swap 1 2 2 3    # Error: duplicate numbers
./push_swap 1 2 abc    # Error: non-numeric input
./push_swap           # Error: no arguments
```

## Project Structure

```
push_swap/
├── Makefile                     # Build configuration
├── README.md                    # This file
├── instructions.txt             # Algorithm documentation
├── includes/
│   └── push_swap.h             # Header file with structures and function declarations
└── src/
    ├── main.c                  # Program entry point and argument handling
    ├── algorithm.c             # Core algorithm implementation
    ├── algorithm_2.c           # Algorithm helper functions
    ├── algorithm_3.c           # Algorithm utility functions
    ├── operations.c            # Stack operations (sa, sb, ss, pa, pb)
    ├── operations_2.c          # Stack operations (ra, rb, rr)
    ├── operations_3.c          # Stack operations (rra, rrb, rrr)
    ├── linkedliststack.c       # Stack data structure implementation
    ├── init_linkedliststack.c  # Stack initialization and node creation
    ├── utilities.c             # Helper functions (find_min, find_max, etc.)
    ├── utilities_2.c           # Additional utility functions
    ├── error_handling.c        # Input validation and error management
    ├── ft_atol.c              # String to long conversion
    └── libft/                 # 42 School's libft library (dependency)
```

## Requirements

### System Requirements
- Unix-like operating system (Linux, macOS)
- GCC compiler with C99 support
- Make utility

### Dependencies
- **libft**: 42 School's custom C library containing functions like:
  - `ft_printf` - Custom printf implementation
  - `ft_putstr_fd` - String output to file descriptor
  - `ft_split` - String splitting function
  - `ft_isdigit` - Character validation

### Compilation Flags
The project compiles with strict flags for robust code:
- `-Wall -Wextra -Werror` - All warnings treated as errors
- `-g` - Debug information included

## Algorithm Complexity

### Time Complexity
- **Best Case**: O(1) - Already sorted
- **Average Case**: O(n log n) - Turk algorithm efficiency
- **Worst Case**: O(n²) - Reverse sorted large stack

### Space Complexity
- O(n) - Uses two stacks with total space proportional to input size

## Testing

To test the program with various inputs:

```bash
# Test with small stacks
./push_swap 3 2 1
./push_swap 2 1 3

# Test with larger stacks
./push_swap 5 4 3 2 1
./push_swap "100 50 25 75 10"

# Test error cases
./push_swap 1 2 2    # Should output "Error"
./push_swap abc      # Should output "Error"
```

## Performance

The Turk algorithm is designed to minimize the number of operations. For reference:
- 3 numbers: ≤ 3 operations
- 5 numbers: ≤ 12 operations  
- 100 numbers: ≤ 700 operations
- 500 numbers: ≤ 5500 operations

## Troubleshooting

### Common Issues

1. **libft not found**: Ensure the libft library is properly installed in `src/libft/`
2. **Compilation errors**: Check that GCC supports the compilation flags used
3. **"Error" output**: Verify input format and check for duplicates or invalid characters

### Debug Mode
Compile with additional debug flags if needed:
```bash
make CFLAGS="-g -Wall -Wextra -Werror -fsanitize=address"
```

## Author

**Omar Tela** (omartela@student.hive.fi)  
42 School - Hive Helsinki

## License

This project is part of the 42 School curriculum. Please respect academic integrity policies when using this code.