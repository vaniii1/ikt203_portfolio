//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TActionStack.h"

TActionStack::TActionStack(){}

TActionStack::~TActionStack() {
    Clear();
}

bool TActionStack::IsEmpty() {
    return count == 0;
}

void TActionStack::Clear() {
    while (!IsEmpty()) delete Pop();
    bottom = 0;
}

void TActionStack::Push(TAction *action) {
    if (count == MAX_SIZE_STACK) {
        delete arr[bottom];
        bottom = (bottom + 1) % MAX_SIZE_STACK;
        count--;
    }
    arr[(bottom + count) % MAX_SIZE_STACK] = action;
    count++;
}

TAction* TActionStack::Pop() {
    if (IsEmpty()) return nullptr;
    count--;
    return arr[(bottom + count) % MAX_SIZE_STACK];

}
