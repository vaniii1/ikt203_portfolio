//
// Created by Ivan Hromovyi on 17/09/2026.
//

#include "TLinkedList.h"
#include <iostream>
#include <ostream>

static void resetSummary(SearchSummary *summary)
{
    summary->comparisons = 0;
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC;
}

static void printSummary(SearchSummary *summary) {
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC - summary->timeSpentMs;
    std::cout << "Comparisons: " << summary->comparisons << ", Time taken : " << summary->timeSpentMs << " seconds." << std::endl;
}

TLinkedList::TLinkedList(bool ownsData, SearchSummary *summary)
    : ownsData(ownsData), summary(summary) {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

TLinkedList::~TLinkedList() {
    Clear();
}

TNode *TLinkedList::GetHead() const {
    return head;
}

TNode *TLinkedList::GetTail() const {
    return tail;
}

// get size of a list
int TLinkedList::GetSize() {
    return size;
}

// empty a list
void TLinkedList::Clear() {
    TNode* cur = head;
    while (cur) {
        TNode* nodeToDelete = cur;
        cur = cur->next;
        if (ownsData) {
            delete nodeToDelete->account;
        }
        delete nodeToDelete;
    }
    head = nullptr;
    tail = head;
    size = 0;
}

// append to a list
void TLinkedList::Append(TBankAccount *account) {
    TNode* newNode = new TNode(account);
    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

// prepend to a list
void TLinkedList::Prepend(TBankAccount *account) {
    TNode* newNode = new TNode(account);
    if (head == nullptr) {
        head = newNode;
        tail = head;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

// get an object by index
TBankAccount* TLinkedList::GetAtIndex(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    TNode* cur;
    int halfSize = size / 2;
    if (index < halfSize) {
        cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = tail;
        for (int i = size - 1; i > halfSize; i--) {
            cur = cur->prev;
        }
    }
    return cur->account;
}

// remove an object by index
bool TLinkedList::RemoveByIndex(int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    TNode* cur;
    if (index < size / 2) {
        cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
    } else {
        cur = tail;
        for (int i = size - 1; i > index; i--) {
            cur = cur->prev;
        }
    }
    if (cur->prev == nullptr) {
        head = cur->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
    } else if (cur->next == nullptr) {
        tail = cur->prev;
        tail->next = nullptr;
    } else {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    delete cur;
    size--;
    return true;
}

// remove by pointer
void TLinkedList::Remove(TBankAccount* account)
{
    TNode* current = head;
    while (current->next != nullptr)
    {
        if (current->next->account == account)
        {
            TNode* temp = current->next;
            current->next = temp->next;
            if (ownsData) delete temp->account;
            delete temp;
            size--;
            return;
        }
        current = current->next;
    }
}

// reverse a list
void TLinkedList::Reverse() {
    TNode* cur = head;
    while (cur != nullptr) {
        TNode* temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;

        cur = temp;
    }

    TNode* temp = tail;
    tail = head;
    head = temp;
}

// print everything in a list
void TLinkedList::PrintAll() const {
    int index = 0;
    TNode* cur = head;
    while (cur != nullptr) {
        std::cout << index++ << ". " << cur->account->ToString() << std::endl;
        cur = cur->next;
    }
}

void TLinkedList::PrintFirst10() const {
    TNode* cur = head;
    for (int i = 0; i < 10; i++) {
        std::cout << i << ". " << cur->account->ToString() << std::endl;
        cur = cur->next;
    }
}

TBankAccount* TLinkedList::Find(FCompareAccount aOnCompare, void* searchKey) {
    resetSummary(summary);
    TBankAccount* result = nullptr;
    TNode* cur = head;
    while (cur != nullptr) {
        summary->comparisons++;
        if (aOnCompare(cur->account, searchKey)) {
            result = cur->account;
            break;
        }
        cur = cur->next;
    }
    printSummary(summary);
    return result;
}

TLinkedList* TLinkedList::Every(FCompareAccount aOnCompare, void* searchKey) {
    resetSummary(summary);
    TLinkedList* results = new TLinkedList(false);
    TNode* cur = head;
    while (cur != nullptr) {
        summary->comparisons++;
        if (aOnCompare(cur->account, searchKey)) {
            results->Append(cur->account);
        }
        cur = cur->next;
    }
    printSummary(summary);
    return results;
}