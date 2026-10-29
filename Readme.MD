# 🌌 IKT203: Algorithms and Data Structures

## 1. Console Text Editor
A C++ console application that simulates document editing abilities. User has an ability to add a line,
insert a line at a certain position, delete a line, display the document (reverse/forward), undo/redo
abilities (implemented with TStack), and print/add document to printing using TQueue.

## 2. Cruise Ship Manifest
A C++ application for managing passenger and employee records on a cruise ship. Data is loaded from a file
and is divided into two TLinkedList (be roles guest/employee). Merge Sort is used to organize lists by last
name and first name. The list is then converted to an array and The Quick Sort Algorithm is being called 
to organize guests by cabin size and last name (helps with cabin assignment). Binary Search is also
implemented for effective passenger lookup by name.

## 3. Employee Directory — BST vs. AVL Tree
A C++ application that implements and compares two tree-based (BST, AVL) data structures used for
managing an employee directory. Trees support insertion, deletion (only BST), searching, and the four traversal 
methods: inorder, preorder, postorder, and level-order. The AVL Tree implements height, balance-factor
calculations and the four rotation cases(LL, RR, LR, RL) to maintain balance and improve search performance.

## 4. Physical Fiber Layout — Prim's Algorithm
A C++ application that calculates the minimum cost of connecting multiple esports arenas. The graph is
represented by an adjacency list and populated from `graph_esport_arenas.txt`. A custom TMinHeap
prioritizes edges by weight, that helps Prim's algorithm to build a Minimum Spanning Tree (MST).
The application displays edges that form the MST and the total cost of the physical network. 
It was accomplished with graph management, file loading, algorithm logic, and output handling
separated into distinct components.
