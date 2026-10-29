//
// Created by Ivan Hromovyi on 29/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TMINHEAP_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TMINHEAP_H

#include "DataStructures/TEdge.hpp"

template <typename T>
class TMinHeap {
private:
    TEdge<T>** heap = nullptr;
    int size = 0;
    int capacity = 0;

    void Resize() {
        int newCapacity = (capacity == 0) ? 4 : capacity * 2;

        TEdge<T>** newHeap = new TEdge<T>*[newCapacity];

        for (int i = 0; i < size; i++) {
            newHeap[i] = heap[i];
        }

        delete[] heap;
        heap = newHeap;
        capacity = newCapacity;
    }

public:
    ~TMinHeap() {
        delete[] heap;
    }

    void Insert(TEdge<T>* edge) {
        if (size == capacity) {
            Resize();
        }

        heap[size] = edge;
        int childIndex = size;
        size++;

        while (childIndex > 0) {
            int parentIndex = (childIndex - 1) / 2;

            if (heap[parentIndex]->GetWeight()
                <= heap[childIndex]->GetWeight()) {
                break;
            }

            TEdge<T>* temp = heap[childIndex];
            heap[childIndex] = heap[parentIndex];
            heap[parentIndex] = temp;

            childIndex = parentIndex;
        }
    }

    TEdge<T>* ExtractMin() {
        if (size == 0) {
            return nullptr;
        }

        TEdge<T>* minEdge = heap[0];

        heap[0] = heap[size - 1];
        size--;

        int index = 0;

        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallest = index;

            if (left < size &&
                heap[left]->GetWeight() < heap[smallest]->GetWeight()) {
                smallest = left;
            }

            if (right < size &&
                heap[right]->GetWeight() < heap[smallest]->GetWeight()) {
                smallest = right;
            }

            if (smallest == index) {
                break;
            }

            TEdge<T>* temp = heap[index];
            heap[index] = heap[smallest];
            heap[smallest] = temp;

            index = smallest;
        }

        return minEdge;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    int GetSize() const {
        return size;
    }
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TMINHEAP_H