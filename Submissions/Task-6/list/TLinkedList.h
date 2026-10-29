//
// Created by Ivan Hromovyi on 17/09/2026.
//

#ifndef BANKING_SYSTEM_SIMPLE_SEARCH_TLINKEDLIST_H
#define BANKING_SYSTEM_SIMPLE_SEARCH_TLINKEDLIST_H
#include "TNode.h"


struct SearchSummary {
    long long comparisons = 0;
    double timeSpentMs = 0.0;
};

static void resetSummary(SearchSummary *summary);
static void printSummary(SearchSummary *summary);

typedef bool (*FCompareAccount)(TBankAccount* account, void* searchKey);

// find conditions
bool CompareByAccountNumber(TBankAccount* account, void* searchKey);
bool CompareByCreationMonth(TBankAccount* account, void* searchKey);
bool CompareByBalance(TBankAccount* account, void* searchKey);

class TLinkedList {
private:
    TNode* head;
    TNode* tail;
    int size;
    bool ownsData;
    SearchSummary *summary;

public:
    TLinkedList(bool ownsData = true, SearchSummary *summary = nullptr);
    ~TLinkedList();

    TNode* GetHead() const;
    TNode* GetTail() const;
    int GetSize();
    void Clear();
    void Append(TBankAccount* account);
    void Prepend(TBankAccount* account);
    TBankAccount* GetAtIndex(int index);
    bool RemoveByIndex(int index);
    void Remove(TBankAccount *account);
    void Reverse();
    void PrintAll() const;
    void PrintFirst10() const;

    TBankAccount* Find(FCompareAccount aOnCompare, void* searchKey);
    TLinkedList* Every(FCompareAccount aOnCompare, void* searchKey);
};

#endif //BANKING_SYSTEM_SIMPLE_SEARCH_TLINKEDLIST_H
