# IAL - Projekt 1

This repository contains implementations of fundamental data structures for the IAL (Algorithms) course at FIT VUT.

## 📋 Project Overview

This project implements several core data structures in C:

- **c201** - Stack (Array-based implementation)
- **c203** - Queue (Array-based implementation)
- **c206** - Doubly Linked List
- **c206-ext** - Extended Doubly Linked List with additional operations

## 🗂️ Repository Structure

```
IAL_1/
├── c201/           # Stack implementation files
├── c201.c          # Stack source code
├── c203/           # Queue implementation files
├── c203.c          # Queue source code
├── c206/           # Doubly linked list implementation files
├── c206.c          # Doubly linked list source code
├── c206-ext/       # Extended doubly linked list implementation files
└── c206-ext.c      # Extended doubly linked list source code
```

## 🛠️ Building and Testing

Each data structure implementation includes its own test files in the respective directories.

### Compilation

Navigate to the specific implementation directory and use the provided Makefile:

```bash
cd c201
make
./c201-test
```

Repeat for other implementations (c203, c206, c206-ext).

### Clean Build Files

```bash
make clean
```

## 📚 Implemented Data Structures

### c201 - Stack (LIFO)

Array-based stack implementation with operations:
- `Stack_Init()` - Initialize empty stack
- `Stack_Push()` - Add element to top
- `Stack_Pop()` - Remove and return top element
- `Stack_Top()` - Return top element without removing
- `Stack_IsEmpty()` - Check if stack is empty
- `Stack_IsFull()` - Check if stack is full

### c203 - Queue (FIFO)

Circular array-based queue implementation with operations:
- `Queue_Init()` - Initialize empty queue
- `Queue_IsEmpty()` - Check if queue is empty
- `Queue_IsFull()` - Check if queue is full
- `Queue_Front()` - Return front element without removing
- `Queue_Remove()` - Remove front element
- `Queue_Get()` - Get and remove front element
- `Queue_Up()` - Add element to rear

### c206 - Doubly Linked List

Implementation of doubly linked list with operations:
- `DLL_Init()` - Initialize empty list
- `DLL_Dispose()` - Dispose all list elements
- `DLL_InsertFirst()` - Insert element at beginning
- `DLL_InsertLast()` - Insert element at end
- `DLL_First()` - Set activity to first element
- `DLL_Last()` - Set activity to last element
- `DLL_GetFirst()` - Get first element value
- `DLL_GetLast()` - Get last element value
- `DLL_DeleteFirst()` - Remove first element
- `DLL_DeleteLast()` - Remove last element
- `DLL_DeleteAfter()` - Remove element after active
- `DLL_DeleteBefore()` - Remove element before active
- `DLL_InsertAfter()` - Insert element after active
- `DLL_InsertBefore()` - Insert element before active
- `DLL_GetValue()` - Get active element value
- `DLL_SetValue()` - Set active element value
- `DLL_Previous()` - Move activity to previous element
- `DLL_Next()` - Move activity to next element
- `DLL_IsActive()` - Check if list has active element

### c206-ext - Extended Doubly Linked List

Extended version of c206 with additional functionality and optimizations.

## 🎓 Course Information

**Course**: IAL (Algorithms)  
**Institution**: Faculty of Information Technology, Brno University of Technology (FIT VUT)  
**Project**: Project 1 - Data Structures Implementation

## ⚙️ Requirements

- GCC compiler
- Make
- Standard C library

## 📝 Testing

Each implementation includes comprehensive test cases that verify:
- Correct initialization
- Proper operation behavior
- Edge cases handling
- Memory management
- Error conditions

Run tests after compilation to verify implementation correctness.

## 🤝 Contributing

This is a student project for academic purposes. The implementations follow the assignment specifications provided by the course instructors.

## 📄 License

Academic project - follow your institution's academic integrity guidelines.

---

**Note**: This project is part of academic coursework. Please ensure compliance with your institution's academic integrity policy when referencing or using this code.
