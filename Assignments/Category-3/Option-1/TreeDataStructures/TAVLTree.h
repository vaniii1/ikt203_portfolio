//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TAVLTREE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TAVLTREE_H

#include <algorithm>
#include "TTreeNode.h"
#include "../models/OperationSummary.h"
#include "DataStructures/TLinkedList.hpp"
#include "DataStructures/TQueue.hpp"

template <typename T>
class TAVLTree {
private:
    TTreeNode<T>* root;
    OperationSummary *summary;

    int GetHeight(TTreeNode<T>* node) {
        return node == nullptr ? 0 : node->height;
    }

    int GetBalance(TTreeNode<T>* node) {
        if (node == nullptr) return 0;
        return GetHeight(node->left) - GetHeight(node->right);
    }

    TTreeNode<T>* RotateRight(TTreeNode<T>* y) {
        TTreeNode<T>* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = 1 + std::max(GetHeight(y->left), GetHeight(y->right));
        x->height = 1 + std::max(GetHeight(x->left), GetHeight(x->right));
        return x;
    }

    TTreeNode<T>* RotateLeft(TTreeNode<T>* x) {
        TTreeNode<T>* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = 1 + std::max(GetHeight(x->left), GetHeight(x->right));
        y->height = 1 + std::max(GetHeight(y->left), GetHeight(y->right));
        return y;
    }

    T* SearchNode(TTreeNode<T>* node, int key) const {
        if (node == nullptr) {
            return nullptr;
        }

        summary->comparisons++;
        if (key == node->key) {
            return &node->value;
        }

        summary->comparisons++;
        if (key < node->key) {
            return SearchNode(node->left, key);
        }

        return SearchNode(node->right, key);
    }

    TTreeNode<T>* InsertHelper(TTreeNode<T>* node, int key, const T& value) {
        if (node == nullptr)
            return new TTreeNode<T>(key, value);

        if (key < node->key)
            node->left = InsertHelper(node->left, key, value);
        else if (key > node->key)
            node->right = InsertHelper(node->right, key, value);
        else
            return node;

        node->height = 1 + std::max(GetHeight(node->left), GetHeight(node->right));

        int b = GetBalance(node);

        // LL
        if (b > 1 && key < node->left->key)
            return RotateRight(node);

        // RR
        if (b < -1 && key > node->right->key)
            return RotateLeft(node);

        // LR
        if (b > 1 && key > node->left->key) {
            node->left = RotateLeft(node->left);
            return RotateRight(node);
        }

        // RL
        if (b < -1 && key < node->right->key) {
            node->right = RotateRight(node->right);
            return RotateLeft(node);
        }

        return node;
    }

    void DestroyHelper(TTreeNode<T>* node) {
        if (node == nullptr) return;
        DestroyHelper(node->left);
        DestroyHelper(node->right);
        delete node;
    }

    void InOrder(TTreeNode<T>* node, TLinkedList<int>& out) {
        if (node == nullptr) return;

        inOrder(node->left, out);
        out.Append(node->key);
        inOrder(node->right, out);
    }

    void PreOrder(TTreeNode<T>* node, TLinkedList<int>& out) {
        if (node == nullptr) return;

        out.Append(node->key);
        preOrder(node->left, out);
        preOrder(node->right, out);
    }

    void PostOrder(TTreeNode<T>* node, TLinkedList<int>& out) {
        if (node == nullptr) return;

        postOrder(node->left, out);
        postOrder(node->right, out);
        out.Append(node->key);
    }

public:
    TAVLTree() : root(nullptr), summary(new OperationSummary()) {}

    ~TAVLTree() {
        DestroyHelper(root);
    }

    void Insert(int key, const T& value) {
        root = InsertHelper(root, key, value);
    }

    T* Search(int key) const {
        std::cout << "------------------AVLTree-------------------" << std::endl;
        resetSummary(summary);
        T* result = SearchNode(root, key);
        printSummary(summary);
        std::cout << "--------------------------------------------" << std::endl;
        return result;
    }

    void InOrder(TLinkedList<int>& out) {
        inOrder(root, out);
    }

    void PreOrder(TLinkedList<int>& out) {
        preOrder(root, out);
    }

    void PostOrder(TLinkedList<int>& out) {
        postOrder(root, out);
    }

    void LevelOrder(TLinkedList<int>& out) {
        if (root == nullptr) return;

        TQueue<TTreeNode<T>*> queue;
        queue.Push(root);

        while (!queue.empty()) {
            TTreeNode<T>* node = queue.Pop();

            out.Append(node->key);

            if (node->left != nullptr)
                queue.Push(node->left);

            if (node->right != nullptr)
                queue.Push(node->right);
        }
    }
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TAVLTREE_H