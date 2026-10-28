#pragma once
#include "TCollection.hpp" // This is your base class for collections
#include "TLinkedList.hpp" // This is your linked list implementation
#include "DebugUtils.h" // This is the provided debug utility for logging
#include <stdexcept> // This is for throwing exceptions when needed

/**
* @file   TQueue.hpp
* @brief  Dear student, this file contains the definition of the TQueue class template, which serves as a queue implementation for storing elements of type T.
*         Be aware that this queue is implemented using a linked list, and it does not own the data it stores.
*         You will create this as a template class typically holding methods for enqueueing, dequeueing, peeking, and checking the size of the queue.
*         Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

template <typename T, int Capacity = 20>
class TQueue : public TCollection<T> {
private:
    T* arr[Capacity];
    int front = 0;
    int back = -1;
    int size = 0;
public:
    TQueue() = default;

    ~TQueue() {
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
            delete Dequeue();
        }
        front = 0;
        back = -1;
    }

    bool Enqueue(T* data) {
        if (size >= Capacity) {
            return false;
        }
        back = (back + 1) % Capacity;
        arr[back] = data;
        size++;
        return true;
    }

    T* Dequeue() {
        if (IsEmpty()) {
            return nullptr;
        }
        T* item = arr[front];
        front = (front + 1) % Capacity;
        size--;
        return item;
    }

    T* Peek() {
        if (IsEmpty()) {
            return nullptr;
        }
        return arr[front];
    }
};