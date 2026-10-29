//
// Created by Ivan Hromovyi on 27/09/2026.
//

#ifndef ALGORITHMIC_ORGANIZER_TSORT_H
#define ALGORITHMIC_ORGANIZER_TSORT_H
#include "../TBankAccount.h"
#include "TLinkedList.h"

struct OperationSummary {
    long long comparisons = 0;
    long long swaps = 0;
    double timeSpentMs = 0.0;
};

static void resetSummary(OperationSummary *summary);
static void printSummary(OperationSummary *summary);

typedef int (*FCompareAccounts)(TBankAccount* a, TBankAccount* b);

// comparisons
int CompareByBalance(TBankAccount* a, TBankAccount* b);
int CompareByAccountNumber(TBankAccount* a, TBankAccount* b);
int CompareByCreationTimestamp(TBankAccount* a, TBankAccount* b);
int CompareByLastName(TBankAccount* a, TBankAccount* b);

class TSort {
public:
    TSort(TBankAccount **array, int size, TLinkedList *list, OperationSummary *summary);
    ~TSort();

    TBankAccount **GetArray() const;
    TBankAccount **GetSortedArray() const;

    // part 2 - O(n^2)
    TBankAccount** SelectionSortArray(FCompareAccounts compareFunc);
    TLinkedList*   SelectionSortList(FCompareAccounts compareFunc);
    TBankAccount** BubbleSortArray(FCompareAccounts compareFunc);

    // part 3 - O(n log n)
    TBankAccount** QuickSortArray(FCompareAccounts compareFunc);
    TLinkedList* MergeSortList(FCompareAccounts compareFunc);

    // part 5 - binary search O(log n)
    TBankAccount* BinarySearch(TBankAccount* target, FCompareAccounts compareFunc);

    // linear search O(n)
    TBankAccount* LinearSearch(TBankAccount *target, FCompareAccounts compareFunc);

    void PrintFirst10InSortedArray() const;
private:
    TBankAccount **array;
    TBankAccount **sortedArray;
    TLinkedList *list;
    int size;
    OperationSummary *summary;
    bool isSorted = false;

    TBankAccount **CopyArray();

    // quick sort array helpers
    void QuickSortRecursive(TBankAccount **arr, int low, int high, FCompareAccounts compareFunc);
    int  Partition(TBankAccount **arr, int low, int high, FCompareAccounts compareFunc);

    // merge sort list helpers
    void MergeSortRecursive(TNode** headRef, FCompareAccounts compareFunc);
    TNode *Merge(TNode* left, TNode* right, FCompareAccounts compareFunc);
    TNode *SplitList(TNode* source);

    // binary search helper
    TBankAccount* BinarySearchRecursive(TBankAccount* target, int low, int high, FCompareAccounts compareFunc);
};


#endif //ALGORITHMIC_ORGANIZER_TSORT_H