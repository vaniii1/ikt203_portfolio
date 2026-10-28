//
// Created by Ivan Hromovyi on 27/10/2026.
//

#include "TSortPersons.h"

TNode<TPerson>* TSortPersons::SplitList(TNode<TPerson> *source) {
    TNode<TPerson>* fast = source;
    TNode<TPerson>* slow = source;
    TNode<TPerson>* slowPrev = nullptr;

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

TNode<TPerson>* TSortPersons::Merge(TNode<TPerson> *a, TNode<TPerson> *b, FComparePersons compareFunc) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    TNode<TPerson>* resultHead = nullptr;
    TNode<TPerson>* resultTail = nullptr;

    if (compareFunc(a->data, b->data) <= 0) {
        resultHead = a;
        a = a->next;
    } else {
        resultHead = b;
        b = b->next;
    }

    resultTail = resultHead;
    while (a != nullptr && b != nullptr) {
        if (compareFunc(a->data, b->data) <= 0) {
            resultTail->next = a;
            resultTail = a;
            a = a->next;
        } else {
            resultTail->next = b;
            resultTail = b;
            b = b->next;
        }
    }

    resultTail->next = (a != nullptr) ? a : b;

    return resultHead;
}

TNode<TPerson>* TSortPersons::MergeSortRecursive(TNode<TPerson> *headRef, FComparePersons compareFunc) {
    if (headRef == nullptr || headRef->next == nullptr) {
        return headRef;
    }

    TNode<TPerson>* left = headRef;
    TNode<TPerson>* right = SplitList(headRef);

    left = MergeSortRecursive(left, compareFunc);
    right = MergeSortRecursive(right, compareFunc);

    return Merge(left, right, compareFunc);
}

void TSortPersons::MergeSort(TLinkedList<TPerson> &list, FComparePersons compareFunc) {
    if (list.head == nullptr || list.head->next == nullptr) {
        return;
    }

    list.head = MergeSortRecursive(list.head, compareFunc);

    // Rebuild the prev pointers and update tail.

    TNode<TPerson>* current = list.head;

    TNode<TPerson>* previous = nullptr;

    while (current != nullptr) {

        current->prev = previous;

        previous = current;

        current = current->next;
    }

    list.tail = previous;
}

void TSortPersons::QuickSortArray(TPerson **array, int size, FComparePersons compareFunc) {
    QuickSortRecursive(array, 0, size - 1, compareFunc);
}

void TSortPersons::QuickSortRecursive(TPerson **arr, int low, int high, FComparePersons compareFunc) {
    if (low < high) {
        int index = Partition(arr, low, high, compareFunc);
        QuickSortRecursive(arr, low, index - 1, compareFunc);
        QuickSortRecursive(arr, index + 1, high, compareFunc);
    }
}

int TSortPersons::Partition(TPerson **arr, int low, int high, FComparePersons compareFunc) {
    TPerson* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (compareFunc(*arr[j], *pivot) < 0) {
            i++;
            TPerson* temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    TPerson* temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}
