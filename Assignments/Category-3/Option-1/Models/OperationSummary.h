//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_OPERATIONSUMMARY_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_OPERATIONSUMMARY_H

struct OperationSummary {
    long comparisons = 0;
    double timeSpentMs = 0.0;
};


static void resetSummary(OperationSummary *summary)
{
    summary->comparisons = 0;
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC;
}

static void printSummary(OperationSummary *summary) {
    summary->timeSpentMs = (static_cast<double>(clock())) / CLOCKS_PER_SEC - summary->timeSpentMs;
    std::cout << "Comparisons: " << summary->comparisons << ", Time taken : " << summary->timeSpentMs << " seconds." << std::endl;
}

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_OPERATIONSUMMARY_H