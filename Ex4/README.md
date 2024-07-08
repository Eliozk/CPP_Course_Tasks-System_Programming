# Project involve Tree's Templates, Iterators and GUI
 
- **My mail:** `kolanielioz@gmail.com` 

## Description
This project implements a generic tree structure using C++ templates. The project includes the following files:

- **Tree.hpp**: Header file defining the `Node`, `Tree`, and `Complex` classes.
- **Tree.tpp**: Implementation file for the `Tree` class methods.
- **main.cpp**: A file demonstrating the usage of the `Tree` class.
- **test_cases.cpp**: Additional test cases covering various tree operations, including traversal and node finding functionalities.

- **Makefile**: A makefile to compile and run the project.

## Running the Code

### General Commands
- **Compile the project**:
    ```
    make
    ```
- **Run the project**:
    ```
    make tree
    ```
- **Run the tests**:
    ```
    make test
    ```    
- **Clean the project**:
    ```
    make clean
    ```

### Exercise-specific Instructions

#### Tree Structure and Methods

**Tree.hpp**:
- **Node Class**: Defines a templated `Node` class representing nodes in the tree.
- **Complex Class**: Defines a templated `Complex` class representing Complex numbers, with operators for comparison and output stream.
- **Tree Class**: Defines a templated `Tree` class implementing various tree traversal methods.


**Tree.tpp**:
- Contains the implementation of the `Tree` class methods including traversal Iterators  for In-order,Post-order,Pre-order,BFS,DFS etc
also has GUI functions representation the tree data structure.

**main.cpp**:
- Demonstrates the usage of the `Tree` class with various examples.

**Makefile**:
- Provides commands to compile, run, and clean the project.

## Review
This project implements a generic tree data structure in C++ using templates. It includes comprehensive implementations for tree traversal methods such as pre-order, post-order, in-order, BFS, DFS, and min heap order. The use of templates allows flexibility in the type of data stored in the tree nodes. The provided `main.cpp` file serves as demonstration for the functionality of the implemented tree operations.

For more details on the implementation and usage, refer to the respective files in this repository.

