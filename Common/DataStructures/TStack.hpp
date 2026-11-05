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

template <typename T>
class TStack : public TCollection<T> {
public:

private:
    TLinkedList<T*> list{false};

public:
    TStack() = default;

    ~TStack() {
        Clear();
    }

    int GetSize() const override {
        return list.GetSize();
    }

    bool IsEmpty() const override {
        return list.IsEmpty();
    }

    void Clear() override {
        list.Clear();
    }

    void Push(T *data) {
        list.Append(data);
    }

    T* Pop() {
        if (IsEmpty()) return nullptr;
        return list.Remove(list.GetSize() - 1);
    }
};

