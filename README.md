# PCC-CS391 Data Structures and Algorithms

This repository contains C programs for fundamental data structures and algorithms as part of the CS391 course. Each section below includes theory, concepts, diagrams, examples, and a reference to the corresponding code file.

---

## 📚 Data Structures Overview

| Data Structure         | File Name                  | Key Operations         | Use Cases                        |
|-----------------------|----------------------------|-----------------------|----------------------------------|
| Stack                 | `Programs/stack.c`         | Push, Pop, Peek       | Expression eval, Undo, Backtrack |
| Linear Queue          | `Programs/linear_queue.c`  | Enqueue, Dequeue      | Scheduling, Buffering            |
| Circular Queue        | `Programs/circular_queue.c`| Enqueue, Dequeue      | Round-robin, Resource mgmt       |
| Single Linked List    | `Programs/single_linked_list.c` | Insert, Delete, Search | Dynamic memory, List ops         |
| Circular Linked List  | `Programs/circular_linked_list.c` | Insert, Delete, Traverse | Playlists, Scheduling         |
| Sparse Matrix         | `Programs/sparse_matrix.c` | Store, Display        | Efficient matrix storage         |
| Infix to Postfix      | `Programs/infix_to_postfix.c` | Convert              | Expression parsing               |
| Postfix Evaluation    | `Programs/postfix_evaluation.c` | Evaluate             | Expression evaluation            |

---

## 1. Stack

**Theory:**  
A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle.

**Concepts:**  
- Only the top element is accessible.
- Operations: Push (insert), Pop (remove), Peek (view top).

**Diagram:**
```
|   30   |  <- Top
|   20   |
|   10   |
---------
```

**Example:**  
Push 10, 20, 30 → Pop → Stack contains 10, 20.

**Code:**  
See [`Programs/stack.c`](Programs/stack.c)

---

## 2. Linear Queue

**Theory:**  
A queue is a linear structure that follows the First-In-First-Out (FIFO) principle.

**Concepts:**  
- Enqueue (insert at rear), Dequeue (remove from front).
- Used for scheduling and buffering.

**Diagram:**
```
Front -> [10][20][30] <- Rear
```

**Example:**  
Enqueue 10, 20, 30 → Dequeue → Queue contains 20, 30.

**Code:**  
See [`Programs/linear_queue.c`](Programs/linear_queue.c)

---

## 3. Circular Queue

**Theory:**  
A circular queue connects the end of the queue back to the front, forming a circle.

**Concepts:**  
- Efficient use of space.
- Rear wraps to 0 when it reaches the end.

**Diagram:**
```
[30][ ][ ][10][20]
  ^           ^
 Rear       Front
```

**Example:**  
Enqueue 10, 20, 30, Dequeue (10), Enqueue 40 → Queue: 20, 30, 40.

**Code:**  
See [`Programs/circular_queue.c`](Programs/circular_queue.c)

---

## 4. Single Linked List

**Theory:**  
A linked list is a linear collection of nodes, where each node points to the next.

**Concepts:**  
- Dynamic size.
- Insert/delete at any position.

**Diagram:**
```
head -> [10] -> [20] -> [30] -> NULL
```

**Example:**  
Insert 10, 20, 30 → Delete 20 → List: 10, 30.

**Code:**  
See [`Programs/single_linked_list.c`](Programs/single_linked_list.c)

---

## 5. Circular Linked List

**Theory:**  
A circular linked list's last node points back to the head.

**Concepts:**  
- No NULL at the end.
- Useful for round-robin scheduling.

**Diagram:**
```
head -> [10] -> [20] -> [30] --
   ^--------------------------|
```

**Example:**  
Insert 10, 20, 30 → Traverse: 10, 20, 30, 10, ...

**Code:**  
See [`Programs/circular_linked_list.c`](Programs/circular_linked_list.c)

---

## 6. Sparse Matrix

**Theory:**  
A sparse matrix is a matrix with most elements as zero, stored efficiently.

**Concepts:**  
- Only non-zero elements are stored.
- Saves memory.

**Diagram:**
```
[0 0 3]
[0 0 0]
[4 0 0]
Stored as: (0,2,3), (2,0,4)
```

**Example:**  
Matrix:  
0 0 3  
0 0 0  
4 0 0  
Stored as: (0,2,3), (2,0,4)

**Code:**  
See [`Programs/sparse_matrix.c`](Programs/sparse_matrix.c)

---

## 7. Infix to Postfix

**Theory:**  
Converts infix expressions (A+B) to postfix (AB+).

**Concepts:**  
- Uses stack for operators.
- Operator precedence is handled.

**Diagram:**
```
Infix:  A + B * C
Stack:  +, *
Postfix: ABC*+
```

**Example:**  
Infix: (A+B)*C → Postfix: AB+C*

**Code:**  
See [`Programs/infix_to_postfix.c`](Programs/infix_to_postfix.c)

---

## 8. Postfix Evaluation

**Theory:**  
Evaluates postfix expressions using a stack.

**Concepts:**  
- Operands pushed to stack.
- Operators pop operands, push result.

**Diagram:**
```
Postfix: 23*5+
Stack: [6, 5] → [11]
```

**Example:**  
Postfix: 23*5+ → (2*3)+5 = 11

**Code:**  
See [`Programs/postfix_evaluation.c`](Programs/postfix_evaluation.c)

---

## 🛠️ Compilation & Execution

```bash
gcc -o stack Programs/stack.c
./stack
# Repeat for other files
```

---

## 🎯 Learning Objectives

- Understand and implement core data structures.
- Practice pointer and memory management in C.
- Apply algorithms to real-world problems.

---

**Course:** CS391  
**Institution:** PCC  
**Language:** C  
**Environment:** Linux/Unix
