#pragma once

/**
* @file   TEdge.hpp
* @brief  Dear student, this file contains the definition of the TEdge class template, which represents an edge in a graph data structure.
* 			  The TEdge class holds a source vertex, a destination vertex, and a weight for the edge.
* 				Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

// Add your template here:
template <typename T>
class TVertex;

template <typename T>
class TEdge {
private:
    TVertex<T>* source;
    TVertex<T>* destination;
    float weight;

public:
    TEdge(TVertex<T>* source, TVertex<T>* destination, float weight)
        : source(source), destination(destination), weight(weight) {
    }

    TVertex<T>* GetSource() const {
        return source;
    }

    TVertex<T>* GetDestination() const {
        return destination;
    }

    float GetWeight() const {
        return weight;
    }

    TVertex<T>* GetOther(const TVertex<T>* vertex) const {
        if (vertex == source) {
            return destination;
        }

        if (vertex == destination) {
            return source;
        }

        return nullptr;
    }
};
