//
// Created by Ivan Hromovyi on 28/10/2026.
//

#include "TSearchPersons.h"

TPerson* TSearchPersons::BinarySearchRecursive(
        TPerson** array, const TPerson& target,
        int low, int high,
        FComparePersons compareFunc) {
    if (low > high) {
        return nullptr;
    }

    int mid = low + (high - low) / 2;
    int cmp = compareFunc(target, *array[mid]);

    if (cmp == 0) {
        return array[mid];
    }
    if (cmp < 0) {
        return BinarySearchRecursive(array, target, low, mid - 1, compareFunc);
    }
    return BinarySearchRecursive(array, target, mid + 1, high, compareFunc);
}

TPerson* TSearchPersons::BinarySearch(
        TPerson** array, int size,
        const TPerson& target,
        FComparePersons compareFunc) {
    if (array == nullptr || size <= 0) {
        return nullptr;
    }
    return BinarySearchRecursive(
        array, target, 0, size - 1, compareFunc
    );
}