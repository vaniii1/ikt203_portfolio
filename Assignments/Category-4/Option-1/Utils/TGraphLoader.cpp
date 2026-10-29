//
// Created by Ivan Hromovyi on 29/10/2026.
//

#include "TGraphLoader.h"

#include "StructureReader.h"

TGraph<int>* TGraphLoader::GetGraph() {
    return &graph;
}

bool TGraphLoader::OnNodeRead(const int index, const int total, const std::string& node) {
    graph.AddVertex(node);
    return true;
}

bool TGraphLoader::OnEdgeRead(const int index, const int total, const std::string& fromNode,
    const std::string& toNode, float weight
) {
    TVertex<int>* from = graph.GetVertex(fromNode);
    TVertex<int>* to = graph.GetVertex(toNode);

    if (from == nullptr || to == nullptr) {
        return false;
    }

    graph.AddEdge(from, to, weight);
    return true;
}

void TGraphLoader::DataInit() {
    ReadGraphFromFile(
    GraphEsportArenasFilePath,
    [this](const int index, const int total, const std::string& node) {
        return OnNodeRead(index, total, node);
    },
    [this](const int index, const int total, const std::string& from,
           const std::string& to, const float weight) {
        return OnEdgeRead(index, total, from, to, weight);
    });

}
