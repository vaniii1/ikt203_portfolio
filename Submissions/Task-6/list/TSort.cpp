//
// Created by Ivan Hromovyi on 27/09/2026.
//

#include "TSort.h"

#include <iostream>

static void resetSummary(OperationSummary *summary)
{
    summary->comparisons = 0;
    summary->swaps = 0;
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC;
}

static void printSummary(OperationSummary *summary) {
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC - summary->timeSpentMs;
    std::cout << "Comparisons: " << summary->comparisons << ", Swaps: " << summary->swaps << ", Time taken : " << summary->timeSpentMs << " seconds." << std::endl;
}

TSort::~TSort() {
    delete[] sortedArray;
}

TBankAccount **TSort::GetArray() const {
    return array;
}

TBankAccount **TSort::GetSortedArray() const {
    return sortedArray;
}

TSort::TSort(TBankAccount **array, int size, TLinkedList *list, OperationSummary *summary)
    : array(array), size(size), list(list), summary(summary), sortedArray(nullptr) {}

// selection sort array
TBankAccount ** TSort::SelectionSortArray(FCompareAccounts compareFunc) {
    std::cout << "--------------- Selection sort array start ---------------" << std::endl;
    resetSummary(summary);
    delete[] sortedArray;
    sortedArray = CopyArray();

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            summary->comparisons++;
            if (compareFunc(sortedArray[j], sortedArray[minIndex]) < 0) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            TBankAccount* temp = sortedArray[i];
            sortedArray[i] = sortedArray[minIndex];
            sortedArray[minIndex] = temp;
            summary->swaps++;
        }
    }

    printSummary(summary);
    PrintFirst10InSortedArray();
    isSorted = true;
    std::cout << "--------------- Selection sort array finish ---------------" << std::endl;
    return sortedArray;
}

// selection sort list
TLinkedList *TSort::SelectionSortList(FCompareAccounts compareFunc) {
    std::cout << "--------------- Selection sort list start ---------------" << std::endl;
    resetSummary(summary);
    TNode* head = nullptr;
    TNode* tail = nullptr;
    for (int i = 0; i < size; i++) {
        TNode* node = new TNode(array[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    TLinkedList* sortedList = new TLinkedList(false);

    while (head) {
        TNode* minNode = head;
        TNode* minPrev = nullptr;
        TNode* prev = head;
        TNode* iter = head->next;

        while (iter) {
            summary->comparisons++;
            if (compareFunc(iter->account, minNode->account) < 0) {
                minNode = iter;
                minPrev = prev;
            }
            prev = iter;
            iter = iter->next;
        }

        sortedList->Append(minNode->account);
        summary->swaps++;

        if (minNode == head) head = head->next;
        else minPrev->next = minNode->next;
        delete minNode;
    }

    printSummary(summary);
    sortedList->PrintFirst10();
    std::cout << "--------------- Selection sort list finish ---------------" << std::endl;
    return sortedList;
}

// bubble sort
TBankAccount **TSort::BubbleSortArray(FCompareAccounts compareFunc) {
    std::cout << "--------------- Bubble sort array start ---------------" << std::endl;
    resetSummary(summary);
    delete[] sortedArray;
    sortedArray = CopyArray();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1 - i; j++) {
            summary->comparisons++;
            if (compareFunc(sortedArray[j], sortedArray[j + 1]) > 0) {
                TBankAccount* temp = sortedArray[j];
                sortedArray[j] = sortedArray[j + 1];
                sortedArray[j + 1] = temp;
                summary->swaps++;
            }
        }
    }
    printSummary(summary);
    PrintFirst10InSortedArray();
    isSorted = true;
    std::cout << "--------------- Bubble sort array finish ---------------" << std::endl;
    return sortedArray;
}

// quick sort list
TBankAccount **TSort::QuickSortArray(FCompareAccounts compareFunc) {
    std::cout << "--------------- Quick sort array start ---------------" << std::endl;
    resetSummary(summary);
    delete[] sortedArray;
    sortedArray = CopyArray();

    QuickSortRecursive(sortedArray, 0, size - 1, compareFunc);

    printSummary(summary);
    PrintFirst10InSortedArray();
    isSorted = true;
    std::cout << "--------------- Quick sort array finish ---------------" << std::endl;
    return sortedArray;
}

void TSort::QuickSortRecursive(TBankAccount **arr, int low, int high, FCompareAccounts compareFunc) {
    if (low < high) {
        int index = Partition(arr, low, high, compareFunc);
        QuickSortRecursive(arr, low, index - 1, compareFunc);
        QuickSortRecursive(arr, index + 1, high, compareFunc);
    }
}

int TSort::Partition(TBankAccount **arr, int low, int high, FCompareAccounts compareFunc) {
    TBankAccount* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        summary->comparisons++;
        if (compareFunc(arr[j], pivot) < 0) {
            i++;
            TBankAccount* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            summary->swaps++;
        }
    }

    TBankAccount* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    summary->swaps++;

    return i + 1;
}

// merge sort list
TLinkedList *TSort::MergeSortList(FCompareAccounts compareFunc) {
    std::cout << "--------------- Merge sort list start ---------------" << std::endl;
    resetSummary(summary);
    TNode* head = nullptr;
    TNode* tail = nullptr;
    for (int i = 0; i < size; i++) {
        TNode* node = new TNode(array[i]);
        if (!head) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    MergeSortRecursive(&head, compareFunc);

    TLinkedList* sortedList = new TLinkedList(false);
    TNode* cur = head;
    while (cur) {
        sortedList->Append(cur->account);
        TNode* toDelete = cur;
        cur = cur->next;
        delete toDelete;
    }

    printSummary(summary);
    sortedList->PrintFirst10();
    std::cout << "--------------- Merge sort list finish ---------------" << std::endl;
    return sortedList;
}

void TSort::PrintFirst10InSortedArray() const {
    if (size >= 10) {
        for (int i = 0; i < 10; i++) {
            std::cout << i << ": " << sortedArray[i]->ToString() << std::endl;
        }
    }
}

void TSort::MergeSortRecursive(TNode** headRef, FCompareAccounts compareFunc) {
    TNode* head = *headRef;

    if (head == nullptr || head->next == nullptr) {
        return;
    }

    TNode* left = head;
    TNode* right = SplitList(head);

    MergeSortRecursive(&left, compareFunc);
    MergeSortRecursive(&right, compareFunc);

    *headRef = Merge(left, right, compareFunc);
}

TNode *TSort::SplitList(TNode* source) {
    TNode* fast = source;
    TNode* slow = source;
    TNode* slowPrev = nullptr;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slowPrev = slow;
        slow = slow->next;
    }

    if (slowPrev != nullptr) {
        slowPrev->next = nullptr;
    }

    return slow;
}

TNode *TSort::Merge(TNode *a, TNode *b, FCompareAccounts compareFunc) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    TNode* resultHead = nullptr;
    TNode* resultTail = nullptr;

    summary->comparisons++;
    if (compareFunc(a->account, b->account) <= 0) {
        resultHead = a;
        a = a->next;
    } else {
        resultHead = b;
        b = b->next;
    }
    resultTail = resultHead;
    summary->swaps++;
    while (a != nullptr && b != nullptr) {
        summary->comparisons++;
        if (compareFunc(a->account, b->account) <= 0) {
            resultTail->next = a;
            resultTail = a;
            a = a->next;
        } else {
            resultTail->next = b;
            resultTail = b;
            b = b->next;
        }
        summary->swaps++;
    }

    resultTail->next = (a != nullptr) ? a : b;

    return resultHead;
}

TBankAccount *TSort::BinarySearch(TBankAccount *target, FCompareAccounts compareFunc) {
    std::cout << "--------------- Binary search start ---------------" << std::endl;

    if (!isSorted) {
        std::cout << "Error: no sorted array available. Call an array sort method first." << std::endl;
        std::cout << "--------------- Binary search finish ---------------" << std::endl;
        return nullptr;
    }

    resetSummary(summary);
    TBankAccount* result = BinarySearchRecursive(target, 0, size - 1, compareFunc);
    printSummary(summary);

    if (result) {
        std::cout << "Found: " << result->ToString() << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }
    std::cout << "--------------- Binary search finish ---------------" << std::endl;
    return result;
}

TBankAccount *TSort::BinarySearchRecursive(
    TBankAccount *target, int low, int high, FCompareAccounts compareFunc) {
    if (low > high) {
        return nullptr;
    }

    int mid = low + (high - low) / 2;
    summary->comparisons++;
    int cmp = compareFunc(target, sortedArray[mid]);

    if (cmp == 0) {
        return sortedArray[mid];
    }
    if (cmp < 0) {
        return BinarySearchRecursive(target, low, mid - 1, compareFunc);
    }
    return BinarySearchRecursive(target, mid + 1, high, compareFunc);
}

TBankAccount * TSort::LinearSearch(TBankAccount *target,
    FCompareAccounts compareFunc) {
    std::cout << "--------------- Linear search start ---------------" << std::endl;
    resetSummary(summary);
    TBankAccount* result = nullptr;
    for (int i = 0; i < size; i++) {
        summary->comparisons++;
        int cmp = compareFunc(target, sortedArray[i]);
        if (cmp == 0) {
             result = sortedArray[i];
            break;
        }
    }
    if (result) {
        std::cout << "Found: " << result->ToString() << std::endl;
    } else {
        std::cout << "Not found." << std::endl;
    }
    printSummary(summary);
    std::cout << "--------------- Linear search finish ---------------" << std::endl;
    return result;
}

TBankAccount **TSort::CopyArray() {
    TBankAccount** copy = new TBankAccount*[size];
    for (int i = 0; i < size; i++) {
        copy[i] = array[i];
    }
    return copy;
}

int CompareByBalance(TBankAccount* a, TBankAccount* b) {
    if (a->GetBalance() < b->GetBalance()) return -1;
    if (a->GetBalance() > b->GetBalance()) return 1;
    return 0;
}

int CompareByAccountNumber(TBankAccount* a, TBankAccount* b) {
    return a->GetAccountNumber().compare(b->GetAccountNumber());
}

int CompareByCreationTimestamp(TBankAccount* a, TBankAccount* b) {
    if (a->GetCreationTimestamp() < b->GetCreationTimestamp()) return -1;
    if (a->GetCreationTimestamp() > b->GetCreationTimestamp()) return 1;
    return 0;
}

int CompareByLastName(TBankAccount* a, TBankAccount* b) {
    return a->GetOwnerLastName().compare(b->GetOwnerLastName());
}
