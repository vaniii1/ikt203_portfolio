//
// Created by Ivan Hromovyi on 29/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHVIEW_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHVIEW_H
#include "DataStructures/TEdge.hpp"
#include "DataStructures/TLinkedList.hpp"
#include <iostream>

class TGraphView {
    public:
    template <typename T>
    static void PrintMST(TLinkedList<TEdge<T>*>& mst) {
        float totalCost = 0;

        std::cout << "----------- Minimum Spanning Tree -----------" << std::endl;

        for (int i = 0; i < mst.GetSize(); i++) {
            TEdge<T>* edge = *mst.GetAtIndex(i);

            std::cout << "Source : " << edge->GetSource()->GetName()
                      << ", Destination : " << edge->GetDestination()->GetName()
                      << ", Cost : " << edge->GetWeight()
                      << '\n';

            totalCost += edge->GetWeight();
        }

        std::cout << "----------------------------------------------" << std::endl;
        std::cout << "Total network cost: " << totalCost << std::endl;
        std::cout << "MST edges: " << mst.GetSize() << std::endl;
    }
};



#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TGRAPHVIEW_H
