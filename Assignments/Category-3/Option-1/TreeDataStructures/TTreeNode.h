//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TTREENODE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TTREENODE_H

template <typename T>
struct TTreeNode {
    int key;
    T value;
    TTreeNode* left;
    TTreeNode* right;
    int height;

    TTreeNode(int key, const T& value)
        : key(key), value(value), left(nullptr), right(nullptr), height(1) {
    }
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TTREENODE_H