//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TJOB_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TJOB_H

#include <string>
#include <utility>

struct TJob {
    int index;
    std::string text;

    TJob(int index, std::string text)
        : index(index), text(std::move(text)) {};
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TJOB_H