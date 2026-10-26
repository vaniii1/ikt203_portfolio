//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_LINKEDLISTNODE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_LINKEDLISTNODE_H
#include <string>

class TNode {
public:
    TNode(std::string line);
    std::string line;
    TNode* next;
    TNode* prev;
};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_LINKEDLISTNODE_H