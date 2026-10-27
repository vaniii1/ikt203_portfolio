#pragma once
#include "TCollection.hpp" // This is your base class for collections
#include "TLinkedList.hpp" // This is your linked list implementation
#include "DebugUtils.h" // This is the provided debug utility for logging
#include <stdexcept> // This is for throwing exceptions when needed

/**
* @file   TStack.hpp
* @brief  Dear student, this file contains the definition of the TStack class template, which serves as a stack implementation for storing elements of type T.
*         Be aware that this stack is implemented using a linked list, and it does not own the data it stores.
*         You will create this as a template class typically holding methods for pushing, popping, peeking, and checking the size of the stack.
*         Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

template <typename T, int Capacity = 20>
class TStack {
private:
    T* arr[Capacity];
    int bottom = 0;
    int count = 0;

public:

    TStack() {}

    ~TStack() {
        Clear();
    }

    bool IsEmpty() {
        return count == 0;
    }

    void Clear() {
        while (!IsEmpty()) delete Pop();
        bottom = 0;
    }

    void Push(T *action) {
        if (count == Capacity) {
            delete arr[bottom];
            bottom = (bottom + 1) % Capacity;
            count--;
        }
        arr[(bottom + count) % Capacity] = action;
        count++;
    }

    T* Pop() {
        if (IsEmpty()) return nullptr;
        count--;
        return arr[(bottom + count) % Capacity];
    }
};

