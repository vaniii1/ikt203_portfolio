#pragma once

/**
* @file   TGraph.hpp
* @brief  Dear student, this file contains the definition of the TGraph class template, which represents a graph data structure.
* 			  The TGraph class holds a collection of vertices and edges, and provides methods for inserting and retrieving them.
* 				Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

// Add your template here:
#include <string>
#include "TLinkedList.hpp"
#include "TVertex.hpp"
#include "TEdge.hpp"

template <typename T>
class TGraph {
private:
    TLinkedList<TVertex<T>*> vertices;
    TLinkedList<TEdge<T>*> edges;

public:
    TGraph() = default;

    ~TGraph() {
        for (auto* current = edges.head;
             current != nullptr;
             current = current->next) {

            delete current->data;
        }

        for (auto* current = vertices.head;
            current != nullptr;
            current = current->next) {

            delete current->data;
        }
    }

    TVertex<T>* AddVertex(const std::string& name) {
        TVertex<T>* existing = GetVertex(name);

        if (existing != nullptr) {
            return existing;
        }

        TVertex<T>* vertex = new TVertex<T>(name);

        vertices.Append(vertex);

        return vertex;
    }

    void AddEdge(
        TVertex<T>* from,
        TVertex<T>* to,
        float weight
    ) {
        if (from == nullptr || to == nullptr) {
            return;
        }

        TEdge<T>* edge = new TEdge<T>(from, to, weight);

        from->AddEdge(edge);
        to->AddEdge(edge);

        edges.Append(edge);
    }

    TVertex<T>* GetVertex(const std::string& name) {
        for (auto* current = vertices.head;
             current != nullptr;
             current = current->next) {

            TVertex<T>* vertex = current->data;

            if (vertex->GetName() == name) {
                return vertex;
            }
        }

        return nullptr;
    }

    TVertex<T>* GetVertexAt(int index) {
        TVertex<T>** vertex = vertices.GetAtIndex(index);

        return vertex != nullptr ? *vertex : nullptr;
    }

    int GetVertexCount() const {
        return vertices.GetSize();
    }

    int GetEdgeCount() const {
        return edges.GetSize();
    }
};