# PriorityQueue
This C++ project implements a priority queue-based system for managing widget orders. It's designed to simulate a real-world order processing system where orders are prioritized based on certain criteria.

# Table of Contents
1. [Features](#features)
2. [System Requirements](#system-requirements)
3. [Installation and Setup](#installation-and-setup)
4. [Usage](#usage)
   - [Main Menu](#main-menu)
   - [Placing Orders](#placing-orders)
   - [Processing Daily Orders](#processing-daily-orders)
5. [Technical Implementation](#technical-implementation)
   - [Priority Queue and Heap Data Structures](#priority-queue-and-heap-data-structures)
   - [Object-Oriented Programming](#object-oriented-programming)
   - [Exception Handling](#exception-handling)
   - [Advanced C++ Features](#advanced-c-features)
   - [Algorithmic Implementation](#algorithmic-implementation)
   - [Code Structure and Style](#code-structure-and-style)
6. [Contributing](#contributing)
7. [Contact Information](#contact-information)

# Features

![Console Application Screenshot](https://private-user-images.githubusercontent.com/31682816/285629018-dfc9dbe7-de92-4710-adb7-4cffd108da30.png?jwt=eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpc3MiOiJnaXRodWIuY29tIiwiYXVkIjoicmF3LmdpdGh1YnVzZXJjb250ZW50LmNvbSIsImtleSI6ImtleTEiLCJleHAiOjE3MDA5NzMwNzEsIm5iZiI6MTcwMDk3Mjc3MSwicGF0aCI6Ii8zMTY4MjgxNi8yODU2MjkwMTgtZGZjOWRiZTctZGU5Mi00NzEwLWFkYjctNGNmZmQxMDhkYTMwLnBuZz9YLUFtei1BbGdvcml0aG09QVdTNC1ITUFDLVNIQTI1NiZYLUFtei1DcmVkZW50aWFsPUFLSUFJV05KWUFYNENTVkVINTNBJTJGMjAyMzExMjYlMkZ1cy1lYXN0LTElMkZzMyUyRmF3czRfcmVxdWVzdCZYLUFtei1EYXRlPTIwMjMxMTI2VDA0MjYxMVomWC1BbXotRXhwaXJlcz0zMDAmWC1BbXotU2lnbmF0dXJlPWI0Y2MzYWNkN2FkOGQ3NzFjMjFkZTdjZjdmNTZkMjE0NjJkYmU1ZmE0MWQwM2U3ZWExZWMyNTVmNDM1NDNkZjkmWC1BbXotU2lnbmVkSGVhZGVycz1ob3N0JmFjdG9yX2lkPTAma2V5X2lkPTAmcmVwb19pZD0wIn0.HHtTvpBr8e2sbDPNaossHHjPitmvq2_-ZQ-TxlpeAY0)

- **Priority Queue Implementation**: Efficiently manages orders based on priority.
- **Order Processing**: Simulates daily order processing in a business environment.
- **User-Friendly Interface**: Provides an easy-to-navigate menu for placing and viewing orders.

# System Requirements

- **Operating System**: Windows, Linux, or MacOS.
- **Compiler**: C++ compiler (GCC, Clang, MSVC) with C++11 support or higher.

# Installation and Setup

1. Clone the repository: `git clone [[repository-url](https://github.com/danieldotwav/PriorityQueue)]`.
2. Navigate to the project directory.
3. Compile the project: `g++ -o priorityQueue Source.cpp`
4. Run the compiled executable: `./priorityQueue`.

# Usage

## Main Menu

The main menu offers options to place a new order, view existing orders, and process daily orders.

## Placing Orders

- Select 'Place Order' from the main menu.
- Follow the prompts to specify order details.
- The order is then added to the priority queue.

## Processing Daily Orders

- Select 'Process Orders' to simulate the processing of daily orders.
- Orders will be processed based on their priority.

# Technical Implementation

# Technical Implementation

This section outlines the sophisticated C++ concepts and techniques employed in the development of the priority queue-based widget ordering system.

## Priority Queue and Heap Data Structures

- **Custom Priority Queue Implementation**: The project features a custom priority queue, specifically tailored for order management. This demonstrates an understanding of data structure design and application.
- **Heap Data Structure**: Utilizes a heap data structure to efficiently manage the priority queue, showcasing knowledge in advanced data structures.

## Object-Oriented Programming

- **Classes and Objects**: The system is designed using object-oriented principles, with classes like `Order` and `PriorityQueue` representing different entities and functionalities.
- **Operator Overloading**: Implements operator overloading (e.g., `<` and `<=` in the `Order` class) to compare orders based on rush status, demonstrating an understanding of C++'s powerful object-oriented features.

## Exception Handling

- **Robust Exception Handling**: Implements custom exception classes (`FullPQ` and `EmptyPQ`) to manage exceptional situations in the priority queue operations, ensuring the robustness of the system.

## Advanced C++ Features

- **Use of Standard Template Library (STL)**: Although the core data structures are custom-implemented, the code reflects an understanding of the STL, evident in the usage of standard headers and namespaces.
- **Dynamic Memory Management**: The design likely involves dynamic memory management, crucial for handling data structures like heaps and priority queues.

## Algorithmic Implementation

- **Efficient Algorithms**: Implements efficient algorithms for re-heapifying the heap (`reheapUp` and `reheapDown`), crucial for maintaining the heap property of the priority queue.

## Code Structure and Style

- **Modular Code Design**: The project is structured into multiple header and source files, each serving a distinct purpose, which is a good practice for maintaining code modularity and readability.

# Contributing

Contributions to this project are welcome. Please follow the standard fork-and-pull request workflow. Make sure to adhere to coding standards and add tests for new features.

# Contact Information

For any queries or support related to this project, please contact:

- **Developer**: [Daniel Rivas]
- **GitHub Profile**: [github.com/danieldotwav]
