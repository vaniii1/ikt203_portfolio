#include <iostream>

#include "list/ListInit.h"
#include "list/TLinkedList.h"
#include "list/TSort.h"

int main() {
    srand((unsigned)time(nullptr));

    int size = 5000;
    TBankAccount** accountArray;
    TLinkedList list(true);

    // populating the data
    ListInit::Populate(list, accountArray, size);

    OperationSummary operationSummary;

    TSort sort(accountArray, size, &list, &operationSummary);

    // part 2
    sort.SelectionSortArray(CompareByBalance);
    sort.SelectionSortList(CompareByBalance);
    sort.BubbleSortArray(CompareByBalance);

    // part 3
    sort.QuickSortArray(CompareByBalance);
    sort.MergeSortList(CompareByBalance);

    // part 5
    TBankAccount *target = sort.GetSortedArray()[100];
    TBankAccount* binaryResult = sort.BinarySearch(target, CompareByBalance);
    TBankAccount* linearResult = sort.LinearSearch(target, CompareByBalance);

    if (binaryResult == target && linearResult == target) {
        std::cout << "search result matched" << std::endl;
    } else {
        std::cout << "search result didnt match" << std::endl;
    }

    return 0;
}

// the report can be found at /resources/report_assignment6_ikt203_ivanh.pdf
