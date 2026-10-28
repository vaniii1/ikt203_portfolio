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
class TStack : public TCollection<T> {
private:
    T* arr[Capacity];
    int bottom = 0;
    int size = 0;

public:

    TStack() = default;

    ~TStack() {
        Clear();
    }

    int GetSize() const override {
        return size;
    }

    bool IsEmpty() const override {
        return size == 0;
    }

    void Clear() override {
        while (!IsEmpty()) {
            delete Pop();
        }
        bottom = 0;
    }

    void Push(T *action) {
        if (size == Capacity) {
            delete arr[bottom];
            bottom = (bottom + 1) % Capacity;
            size--;
        }
        arr[(bottom + size) % Capacity] = action;
        size++;
    }

    T* Pop() {
        if (IsEmpty()) return nullptr;
        size--;
        return arr[(bottom + size) % Capacity];
    }
};

