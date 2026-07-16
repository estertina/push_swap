_This project has been created as part of the 42 curriculum by **esttina**._

# push_swap

This project is part of the 42 curriculum and aims to sort data on a stack with a limited set of instructions and in as few operations as possible. To achieve this, various sorting algorithms must be understood and implemented – from simple logic for small datasets to highly scalable algorithms like Radix Sort for large datasets.

---

## 1. Validation, Parsing, and Ranking

Before any sorting occurs, the input data must be processed and checked for errors.

### Validation
Every program that processes user input must be robust. Validation checks if:
* The input consists only of valid numbers (no letters or special characters, except `-`/`+` at the beginning).
* No number exceeds or falls below the integer limits (`2147483647` to `-2147483648`).
* There are no duplicates.

### Parsing
The input arguments are passed as strings. If they are passed as a single string enclosed in quotes (e.g., `"1 5 4 2"`), they must first be split (`ft_split`) and then converted into actual integer values using a function like `ft_atoi`. 

### Ranking (Indexing)
Instead of calculating directly with the provided numbers, we assign each number a "rank" (index) based on its size in the entire array. The smallest number gets the rank `0`, the next `1`, etc. 
* *Why?* Since Radix Sort handles negative numbers poorly and large numbers would require an unnecessarily high number of bit shifts, ranking simplifies the process massively. In the end, we only sort a dense sequence of positive numbers, starting at `0`.

---

## 2. Small Sort Algorithm

Radix Sort is great for many numbers, but extremely inefficient for very small sets. Therefore, we use hardcoded "Small Sort" algorithms for arrays of up to 5 elements.

* **3 Numbers:** There are only 5 possible permutations when the numbers are unsorted. With a maximum of 2 instructions (e.g., `sa`, `ra`, `rra`), any of these orders can be sorted.
* **4 to 5 Numbers:** We find the smallest (and second smallest) number in Stack A and push them to Stack B (`pb`). Then we only have 3 numbers left in Stack A, which we sort using the efficient 3-sort. Finally, we simply push the numbers from Stack B back to A (`pa`).

---

## 3. Radix Sort Algorithm

### Definition
Radix Sort is a non-comparative sorting algorithm. Instead of comparing numbers directly with each other (like Quick Sort), it sorts numbers based on their individual digits (or bits). For `push_swap`, we use the **Binary Radix Sort** (Base 2). We look at the numbers bit by bit, from the least significant bit (far right, LSB) to the most significant bit (far left, MSB).

### Simple Example: `2, 4, 0, 1, 3`

Let's look at the numbers in binary format. We need 3 bits to represent all numbers up to 4:
* **2** = `010`
* **4** = `100`
* **0** = `000`
* **1** = `001`
* **3** = `011`

**How the algorithm works:**
We go through all numbers in Stack A for each bit level (starting with the 0th bit on the far right).
* If the bit is a **`0`**, we push the number to Stack B (`pb`).
* If the bit is a **`1`**, we keep the number in Stack A by rotating it downwards (`ra`).
* When we have processed all numbers, we push everything from Stack B back to Stack A (`pa`).

**Step-by-Step Process:**

**Initial Stack A:** `2, 4, 0, 1, 3`

**Bit 0 (check far right, LSB):**
* `2 (010)` -> Bit is 0 -> `pb`
* `4 (100)` -> Bit is 0 -> `pb`
* `0 (000)` -> Bit is 0 -> `pb`
* `1 (001)` -> Bit is 1 -> `ra`
* `3 (011)` -> Bit is 1 -> `ra`
* *After pushing everything back (`pa`), Stack A is:* `2, 4, 0, 1, 3`
*(Note: The stack order happens to look identical to the start, but it is now logically grouped by the 0th bit. The zeros `2, 4, 0` are at the top, and the ones `1, 3` are at the bottom).*

**Bit 1 (check middle bit):**
* `2 (010)` -> Bit is 1 -> `ra`
* `4 (100)` -> Bit is 0 -> `pb`
* `0 (000)` -> Bit is 0 -> `pb`
* `1 (001)` -> Bit is 0 -> `pb`
* `3 (011)` -> Bit is 1 -> `ra`
* *After pushing everything back (`pa`), Stack A is:* `4, 0, 1, 2, 3`
*(Now grouped by the 1st bit: `4, 0, 1` have a `0` in the middle, while `2, 3` have a `1`).*

**Bit 2 (check far left bit, MSB):**
* `4 (100)` -> Bit is 1 -> `ra`
* `0 (000)` -> Bit is 0 -> `pb`
* `1 (001)` -> Bit is 0 -> `pb`
* `2 (010)` -> Bit is 0 -> `pb`
* `3 (011)` -> Bit is 0 -> `pb`
* *After pushing everything back (`pa`), Stack A is:* `0, 1, 2, 3, 4`
* *The stack is now perfectly sorted! All zeros were systematically filtered out and brought to the front without ever having to compare `Number A > Number B`.*

---

## 4. Project Structure

A clean C project under Linux requires a clear structure:

```text
.
├── Makefile
├── inc/
│   └── push_swap.h        # Header files, Structs, Prototypes
├── src/
│   ├── index.c            # Assigning ranks
│   ├── list_utils.c       # Linked list functions
│   ├── main.c             # Main function, Error Handling
│   ├── push.c             # pa, pb
│   ├── radix.c            # Binary Radix Sort
│   ├── rev_rotate.c       # rra, rrb, rrr
│   ├── rotate.c           # ra, rb, rr
│   ├── sort_small.c       # Algorithm for <= 5 numbers
│   ├── swap.c             # sa, sb, ss
│   └── utils.c            # Validation, Parsing
└── libft/                 # For ft_split
```

---

## 5. Compilation and Execution

The program is compiled simply using the Makefile:
```bash
make
```
```bash
# To execute it, you pass the numbers as a single string:
./push_swap "2 4 0 1 3"

# To execute it, you pass the numbers as arguments:
./push_swap 2 4 0 1 3
```
*Output:* The list of instructions (e.g., `ra`, `pb`, `pa` ...) to sort the list.


---

## 6. Checking for Memory Leaks with Valgrind

To ensure no memory leaks occurred due to faulty `malloc`/`free` or `ft_split`, we use Valgrind. It catches all memory access errors and un-freed blocks:

```bash
# Test a single string
valgrind --leak-check=full ./push_swap "2 3 1"

# Test multiple arguments
valgrind --leak-check=full ./push_swap 2 4 0 1 3 5
```
*The goal is to see the phrase "All heap blocks were freed -- no leaks are possible" at the end of the output.*

---

## 7. The Linux Checker (`linux_checker`)

The checker verifies whether the instructions your `push_swap` outputs actually sort the stack. You pipe the output of your program directly into the checker.

### You can also use Basic Tests:

*(Note: The `checker_linux` file must have execution rights. If it doesn't: run `chmod +x checker_linux` in your terminal).*

```bash
# 3 numbers (sorted in max. 2-3 moves)
ARG="2 3 1"; ./push_swap $ARG | ./checker_linux $ARG

# 5 numbers (sorted in max. 12 moves)
ARG="4 2 5 1 3"; ./push_swap $ARG | ./checker_linux $ARG
```

---

### Test with (100 & 500 Numbers)
**100 Numbers Test (less than 1100 operations)**
```bash
ARG=$(seq 1 1000 | shuf -n 100 | tr '\n' ' '); \
./push_swap $ARG | ./checker_linux $ARG; \
./push_swap $ARG | wc -l
```

**500 Numbers Test (less than 7000 operations)**
```bash
ARG=$(seq 1 5000 | shuf -n 500 | tr '\n' ' '); \
./push_swap $ARG | ./checker_linux $ARG; \
./push_swap $ARG | wc -l
```


---

## 8. Visualization

Sometimes it's hard to mentally trace raw console outputs. A visualizer helps immensely to "watch the algorithm think" and check if the stacks are being pushed back and forth as expected.

**Steps to build and run the visualizer:**

```bash
# First, compile your push_swap
make

# Clone the visualizer
git clone https://github.com/o-reo/push_swap_visualizer.git push_swap_visualizer
cd push_swap_visualizer

# Create build folder and configure
mkdir builder && cd builder
cmake ..
make

# Run the visualizer
./bin/visualizer
```

In the visualizer interface, you can now specify the path to your `push_swap` executable and watch the sorting process animated.

---

## 9. Resources
* [Radix Sort Algorithm Intro](https://en.wikipedia.org/wiki/Radix_sort)
* [Visualizing Radix Sort (YouTube)](https://www.youtube.com/watch?v=x0FNeXIGrP8) - Very helpful for understanding the shifting of the buckets (stacks).
* [Radix Sort Algorithm Explained - Yogendra Singh](https://medium.com/@ys.yogendra22/radix-sort-sorting-c5b31152c48b)
* [Push_Swap Tutorial - Leo Fu](https://leofu890806.medium.com/push-swap-tutorial-fa746e6aba1e)
* [Push_Swap: The least amount of moves with two stacks - Jamie Dawson](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
* [GitBook 42 - push_swap](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)