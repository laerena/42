*This project has been created as part of the 42 curriculum by leilai.*

# Push_Swap

**push_swap** is a program that sorts a list of integers using two stacks and a limited set of operations.  
The challenge is not simply to sort the numbers, but to do so **using the fewest possible operations** while respecting strict constraints on how the stacks can be manipulated.

This project focuses on **algorithmic thinking, optimization, and system design under constraints**.

---

## Project Overview

The program receives a list of integers as arguments and outputs a sequence of instructions that will sort the numbers in ascending order.

Two stacks are used:

- **Stack A** – initially contains all numbers
- **Stack B** – initially empty

The goal is to transform stack A into a sorted stack using only a restricted set of operations.


## Allowed Operations

The following operations manipulate the stacks:

#### Swap
Swap the first two elements of a stack.
- sa – swap top two of A
- sb – swap top two of B
- ss – sa and sb at the same time

#### Push
Move the top element from one stack to the other.
- pa – push top of B to A
- pb – push top of A to B


#### Rotate
Shift all elements up by one.
- ra – rotate A
- rb – rotate B
- rr – rotate A and B


#### Reverse Rotate
Shift all elements down by one.
- rra – reverse rotate A
- rrb – reverse rotate B
- rrr – reverse rotate A and B

Each instruction must be printed exactly once per line.


## Input Normalization

Before sorting begins, the input values are **normalized**.

Normalization replaces each number with its **rank in the sorted order**, while preserving the relative ordering of values.

Example:
- Input: [-42, 100, 7]
- Sorted: [-42, 7, 100]
- Normalized: -42 -> 0, 7 -> 1, 100 -> 2

This transformation simplifies the problem by converting arbitrary integers into a predictable range `[0..n-1]`.

Normalization also makes algorithms like **radix sort** easier to implement.

---

## Algorithms Implemented

This project explores multiple algorithmic approaches to the push_swap problem.

### Small Sort

For very small inputs (≤5 numbers), specialized logic is used.

These cases are solved using deterministic patterns that produce the minimum possible number of operations.



### Radix Sort

Radix sort is a **bitwise sorting algorithm** that processes numbers digit by digit.

Instead of comparing values, it partitions numbers based on the value of individual bits.

Radix sort characteristics:

- deterministic
- mechanical
- based on bit manipulation
- time complexity: **O(n log n)**

Bit operations used:
- x >> k - shift bits right by k positions
- (x >> k) & 1 - extract bit k
	
	Example:
	- 6 = 110 (binary)
	- ((6 >> 0) & 1) = 0
	- ((6 >> 1) & 1) = 1
	- ((6 >> 2) & 1) = 1

Radix repeatedly partitions values between stacks A and B based on these bits until the numbers become sorted.

Radix is algorithmically elegant but **does not optimize stack movement**.



### Chunk Sort

Chunk sorting divides the input into **ranges (chunks)** of values.

The algorithm works in two phases:

1. **Push Phase**
   - Numbers belonging to the current chunk are pushed from A to B.
   - Rotations help reduce unnecessary moves.

2. **Rebuild Phase**
   - The largest numbers are extracted from B and pushed back to A.

This approach is a heuristic strategy that balances simplicity and performance.

It works well for medium-sized inputs.



### Turk Algorithm (Cost-Based)

The Turk method uses a **cost calculation strategy** to determine the best move at each step.

For every element in stack B:

1. Calculate the cost to rotate stack A to the correct insertion point.
2. Calculate the cost to rotate stack B to bring that element to the top.
3. Combine rotations when possible (`rr` or `rrr`).

The algorithm then selects the move with the **lowest total cost**.

Characteristics:

- greedy optimization
- considers stack geometry
- reduces unnecessary rotations
- often produces fewer operations than simpler strategies

---

## Complexity

Algorithm performance is typically described using **Big-O notation**.

Examples:
- O(n) – process each element once
- O(n²) – compare every element to every other element
- O(n log n) – divide and conquer style growth

For push_swap, complexity is slightly less important than **the number of operations generated**, since the program’s output length is what is evaluated.

---

## Program Architecture

The project is organized around clear separation of responsibilities.

#### Stack Operations

Each operation performs two tasks:

1. **Update the internal stack state**
2. **Print the corresponding instruction**

Separating state changes from output makes the implementation easier to maintain and test.



#### Encapsulation and API Design

The project follows basic API design principles:

- Internal stack manipulation is hidden inside implementation files
- Only necessary functions are exposed through headers
- The rest of the program interacts through a defined interface

This improves modularity and prevents unintended dependencies.

---

## Learning Objectives

Through this project I focused on developing several core programming skills.

#### Algorithmic Thinking

- reasoning about state transitions
- designing strategies under constraints
- comparing multiple algorithmic approaches

#### Performance Optimization

- minimizing operation count
- measuring algorithm efficiency
- tuning heuristics to reduce moves

#### Systems Design

- designing clear APIs
- separating internal logic from output
- organizing code into maintainable modules

#### Data Representation

- simplifying problems through normalization
- using bitwise operations to implement radix sort

Overall, this project reinforced the importance of **thinking about algorithms not only in terms of correctness, but also efficiency and system design**.

---

## AI Usage

AI tools were used as a learning aid for:

- reviewing algorithm concepts
- discussing optimization strategies
- improving documentation structure

All implementation and debugging work was performed by the author.