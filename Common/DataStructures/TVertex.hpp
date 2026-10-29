#pragma once

/**
* @file   TVertex.hpp
* @brief  Dear student, this file contains the definition of the TVertex class template, which represents a vertex in a graph data structure.
* 			  The TVertex class holds a name, a payload (which is typically a pointer to a specific object), and a list of incident edges.
* 				Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

// Add your template here:
#include <string>
#include "TLinkedList.hpp"
#include "TEdge.hpp"

template <typename T>
class TVertex {
private:
    std::string name;
    T* payload;
    TLinkedList<TEdge<T>*> edges;

public:
    explicit TVertex(const std::string& name, T* payload = nullptr)
        : name(name), payload(payload) {
    }

    const std::string& GetName() const {
        return name;
    }

    T* GetPayload() const {
        return payload;
    }

    void SetPayload(T* newPayload) {
        payload = newPayload;
    }

    void AddEdge(TEdge<T>* edge) {
        if (edge != nullptr) {
            edges.Append(edge);
        }
    }

    int GetEdgeCount() const {
        return edges.GetSize();
    }

    TEdge<T>* GetEdgeAt(int index) {
        TEdge<T>** edge = edges.GetAtIndex(index);

        return edge != nullptr ? *edge : nullptr;
    }

    TVertex<T>* GetNeighborAt(int index) {
        TEdge<T>* edge = GetEdgeAt(index);

        return edge != nullptr ? edge->GetOther(this) : nullptr;
    }

    TEdge<T>* GetEdgeTo(TVertex<T>* other) {
        for (auto* current = edges.head;
             current != nullptr;
             current = current->next) {

            TEdge<T>* edge = current->data;

            if (edge->GetOther(this) == other) {
                return edge;
            }
        }

        return nullptr;
    }
};
