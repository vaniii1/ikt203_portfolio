//
// Created by Ivan Hromovyi on 07/09/2026.
//

#ifndef STACK_QUEUE_TSTACK_H
#define STACK_QUEUE_TSTACK_H

const int MAX_SIZE_STACK = 10000;

class TStack {
private:
    int arr[MAX_SIZE_STACK];
    int top = -1;
public:
    TStack();
    void Push(int item);
    int Pop();
    int Peek();
    bool IsEmpty();
};


#endif //STACK_QUEUE_TSTACK_H