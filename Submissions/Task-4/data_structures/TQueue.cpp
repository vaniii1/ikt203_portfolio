//
// Created by Ivan Hromovyi on 07/09/2026.
//

#include "TQueue.h"

#include <iostream>
#include <ostream>

TQueue::TQueue(){}

// Time: O(1), Space: O(1)
bool TQueue::IsEmpty() {
    return itemCount == 0;
}

// Time: O(1), Space: O(1)
void TQueue::Enqueue(int item) {
    if (itemCount >= MAX_SIZE_QUEUE) {
        std::cout << "Queue is full" << std::endl;
        return;
    }
    back = (back + 1) % MAX_SIZE_QUEUE;
    arr[back] = item;
    itemCount++;
}

// Time: O(1), Space: O(1)
int TQueue::Dequeue() {
    if (IsEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    int item = arr[front];
    front = (front + 1) % MAX_SIZE_QUEUE;
    itemCount--;
    return item;
}

// Time: O(1), Space: O(1)
int TQueue::Peek() {
    if (IsEmpty()) {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }
    return arr[front];
}