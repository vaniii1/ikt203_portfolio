//
// Created by Ivan Hromovyi on 07/09/2026.
//

#include "TStack.h"

#include <iostream>

TStack::TStack(){}

// Time: O(1), Space: O(1)
bool TStack::IsEmpty() {
    return top == -1;
}

// Time: O(1), Space: O(1)
void TStack::Push(int item) {
    if (top == MAX_SIZE_STACK - 1) {
        std::cout << "Stack is full" << std::endl;
        return;
    }
    arr[++top] = item;
}

// Time: O(1), Space: O(1)
int TStack::Pop() {
    if (IsEmpty()) {
        std::cout << "Stack is empty" << std::endl;
        return -1;
    }
    return arr[top--];
}

// Time: O(1), Space: O(1)
int TStack::Peek() {
    if (IsEmpty()) {
        return -1;
    }
    return arr[top];
}

