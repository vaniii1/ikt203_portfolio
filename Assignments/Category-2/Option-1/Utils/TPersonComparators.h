//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TPERSONCOMPARATORS_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TPERSONCOMPARATORS_H

#include "../Models/TPerson.h"

inline int compareByName(const TPerson& a, const TPerson& b) {
    if (a.lastName < b.lastName) {
        return -1;
    }

    if (a.lastName > b.lastName) {
        return 1;
    }

    if (a.firstName < b.firstName) {
        return -1;
    }

    if (a.firstName > b.firstName) {
        return 1;
    }

    return 0;
}

inline int compareByCabinAndLastName(const TPerson &a, const TPerson &b) {
    if (a.cabinSize < b.cabinSize) {
        return -1;
    }

    if (a.cabinSize > b.cabinSize) {
        return 1;
    }

    if (a.lastName < b.lastName) {
        return -1;
    }

    if (a.lastName > b.lastName) {
        return 1;
    }

    return 0;
}

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TPERSONCOMPARATORS_H