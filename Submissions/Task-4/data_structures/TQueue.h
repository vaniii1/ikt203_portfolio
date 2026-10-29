//
// Created by Ivan Hromovyi on 07/09/2026.
//

#ifndef STACK_QUEUE_TQUEUE_H
#define STACK_QUEUE_TQUEUE_H

const int MAX_SIZE_QUEUE = 10000;

class TQueue {
    private:
    int arr[MAX_SIZE_QUEUE];
    int front = 0;
    int back = -1;
    int itemCount = 0;
    public:
    TQueue();
    bool IsEmpty();
    void Enqueue(int item);
    int Dequeue();
    int Peek();
};


#endif //STACK_QUEUE_TQUEUE_H