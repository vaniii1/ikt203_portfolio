//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TQueue.h"

TQueue::TQueue(){}

TQueue::~TQueue() {
    Clear();
}

bool TQueue::IsEmpty() {
    return jobCount == 0;
}

bool TQueue::Enqueue(TJob* job) {
    if (jobCount >= MAX_SIZE_QUEUE) {
        return false;
    }
    back = (back + 1) % MAX_SIZE_QUEUE;
    arr[back] = job;
    jobCount++;
    return true;

}

TJob* TQueue::Dequeue() {
    if (IsEmpty()) {
        return nullptr;
    }
    TJob* item = arr[front];
    front = (front + 1) % MAX_SIZE_QUEUE;
    jobCount--;
    return item;
}

TJob* TQueue::Peek() {
    if (IsEmpty()) {
        return nullptr;
    }
    return arr[front];
}

void TQueue::Clear() {
    while (!IsEmpty()) {
        delete Dequeue();
    }
    front = 0;
    back = -1;
}

