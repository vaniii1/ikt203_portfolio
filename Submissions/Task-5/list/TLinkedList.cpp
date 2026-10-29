//
// Created by Ivan Hromovyi on 17/09/2026.
//

#include "TLinkedList.h"
#include <iostream>
#include <ostream>
#include <chrono>
#include <ctime>

void resetSummary(SearchSummary *summary)
{
    if (summary == nullptr) return;

    summary->comparisons = 0;
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC;
}

void printSummary(SearchSummary *summary) {
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC - summary->timeSpentMs;
    std::cout << "Comparisons: " << summary->comparisons
    << ", Time taken : " << summary->timeSpentMs << " seconds." << std::endl;
}

bool CompareByBalance(TBankAccount* account, void* searchKey) {
    const double* key = static_cast<const double*>(searchKey);
    return account->GetAccountBalance() == *key;
}

bool CompareByAccountNumber(TBankAccount* account, void* searchKey) {
    const std::string* key = static_cast<const std::string*>(searchKey);
    return account->GetAccountNumber() == *key;
}

bool CompareByCreationMonth(TBankAccount* account, void* searchKey) {
    const int* targetMonth = static_cast<const int*>(searchKey);
    time_t timestamp = account->GetCreationTimestamp();
    tm parts = *localtime(&timestamp);
    return parts.tm_mon == *targetMonth;
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
bool TLinkedList::Remove(int index) {
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

// find BankAccount by search key
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

// find every BankAccount by search key
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
