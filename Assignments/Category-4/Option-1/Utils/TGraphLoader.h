//
// Created by Ivan Hromovyi on 29/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHLOADER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHLOADER_H


#include "DataStructures/TGraph.hpp"

class TGraphLoader {
private:
    TGraph<int> graph;

    bool OnNodeRead(const int index, const int total, const std::string& node);

    bool OnEdgeRead(const int index, const int total, const std::string& fromNode,
        const std::string& toNode, float weight);

public:
    void DataInit();

    TGraph<int>* GetGraph();
};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHLOADER_H