//
// Created by Ivan Hromovyi on 29/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TPRIM_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TPRIM_H

#include "TMinHeap.h"
#include "DataStructures/TGraph.hpp"

template <typename T>
void PrimMST(TGraph<T>& graph, TLinkedList<TEdge<T>*>& mst) {
    mst.Clear();
    int vertexCount = graph.GetVertexCount();

    if (vertexCount == 0) {
        return;
    }

    bool* visited = new bool[vertexCount]();
    TMinHeap<T> heap;

    visited[0] = true;

    TVertex<T>* start = graph.GetVertexAt(0);

    for (int i = 0; i < start->GetEdgeCount(); i++) {
        heap.Insert(start->GetEdgeAt(i));
    }

    while (!heap.IsEmpty() && mst.GetSize() < vertexCount - 1) {
        TEdge<T>* edge = heap.ExtractMin();

        TVertex<T>* from = edge->GetSource();
        TVertex<T>* to = edge->GetDestination();

        int fromIndex = 0;
        int toIndex = 0;

        while (graph.GetVertexAt(fromIndex) != from) {
            fromIndex++;
        }

        while (graph.GetVertexAt(toIndex) != to) {
            toIndex++;
        }

        if (visited[fromIndex] && visited[toIndex]) {
            continue;
        }

        mst.Append(edge);

        TVertex<T>* next = visited[fromIndex] ? to : from;
        int nextIndex = visited[fromIndex] ? toIndex : fromIndex;

        visited[nextIndex] = true;

        for (int i = 0; i < next->GetEdgeCount(); i++) {
            TEdge<T>* nextEdge = next->GetEdgeAt(i);
            TVertex<T>* neighbor = nextEdge->GetOther(next);

            int neighborIndex = 0;

            while (graph.GetVertexAt(neighborIndex) != neighbor) {
                neighborIndex++;
            }

            if (!visited[neighborIndex]) {
                heap.Insert(nextEdge);
            }
        }
    }

    delete[] visited;
}

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TPRIM_H