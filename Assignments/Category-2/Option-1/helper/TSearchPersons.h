//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TSEARCHPERSONS_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TSEARCHPERSONS_H
#include "../models/TPerson.h"

class TSearchPersons {
private:
    static TPerson* BinarySearchRecursive(
        TPerson** array, const TPerson& target,
        int low, int high,
        FComparePersons compareFunc);

    public:
    static TPerson* BinarySearch(TPerson** array, int size,
        const TPerson& target, FComparePersons compareFunc);
};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TSEARCHPERSONS_H