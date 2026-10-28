//
// Created by Ivan Hromovyi on 27/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TDATASTRUCTURECONVERTER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TDATASTRUCTURECONVERTER_H
#include "DataStructures/TLinkedList.hpp"


template <typename T>
class TDataStructureConverter {
    public:
    static T** FromLinkedListToArray(TLinkedList<T>& list) {
        int size = list.GetSize();
        T** array = new T*[size];

        TNode<T>* current = list.head;

        for (int i = 0; i < size; i++) {
            array[i] = &current->data;
            current = current->next;
        }

        return array;
    }
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TDATASTRUCTURECONVERTER_H
