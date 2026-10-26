//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TNode.h"

#include <utility>

TNode::TNode(std::string line)
    : line(std::move(line)), next(nullptr), prev(nullptr) {
}

