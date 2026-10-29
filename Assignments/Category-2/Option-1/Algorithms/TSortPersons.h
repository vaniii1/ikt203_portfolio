//
// Created by Ivan Hromovyi on 27/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TSORT_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TSORT_H
#include "../Models/TPerson.h"
#include "DataStructures/TLinkedList.hpp"
#include "DataStructures/TNode.hpp"

class TSortPersons {
    static TNode<TPerson>* SplitList(TNode<TPerson>* source);

    static TNode<TPerson>* Merge(TNode<TPerson> *a, TNode<TPerson> *b, FComparePersons compareFunc);

    static TNode<TPerson>* MergeSortRecursive(TNode<TPerson>* headRef, FComparePersons compareFunc);

    static void QuickSortRecursive(TPerson **arr, int low, int high, FComparePersons compareFunc);

    static int Partition(TPerson **arr, int low, int high, FComparePersons compareFunc);
public:
    static void MergeSort(
        TLinkedList<TPerson>& list,
        FComparePersons compareFunc
    );

    static void QuickSortArray(TPerson** array, int size, FComparePersons compareFunc);

};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TSORT_H