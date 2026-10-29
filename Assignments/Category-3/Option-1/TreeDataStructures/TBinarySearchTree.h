//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TBINARYSEARCHTREE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TBINARYSEARCHTREE_H
#include <algorithm>
#include "TTreeNode.h"
#include "../Models/OperationSummary.h"
#include "DataStructures/TQueue.hpp"
#include "DataStructures/TLinkedList.hpp"

template <typename T>
class TBinarySearchTree {
private:
    TTreeNode<T>* root;
    OperationSummary *summary;

    void DeleteSubtree(TTreeNode<T>* node) {
        if (node == nullptr) return;
        DeleteSubtree(node->left);
        DeleteSubtree(node->right);
        delete node;
    }

    bool InsertNode(TTreeNode<T>*& node, int key, const T& value) {
        if (node == nullptr) {
            node = new TTreeNode<T>(key, value);
            return true;
        }
        if (key < node->key) {
            return InsertNode(node->left, key, value);
        }
        if (key > node->key) {
            return InsertNode(node->right, key, value);
        }
        return false;
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

    bool DeleteNode(TTreeNode<T>*& node, int key) {
        if (node == nullptr) return false;

        if (key < node->key) return DeleteNode(node->left, key);
        if (key > node->key) return DeleteNode(node->right, key);

        if (node->left == nullptr || node->right == nullptr) {
            TTreeNode<T>* child = node->left == nullptr ? node->right : node->left;
            delete node;
            node = child;
            return true;
        }

        TTreeNode<T>* successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        node->key = successor->key;
        node->value = successor->value;
        return DeleteNode(node->right, successor->key);
    }

    int HeightOf(TTreeNode<T>* node) const {
        if (node == nullptr) return 0;
        return 1 + std::max(HeightOf(node->left), HeightOf(node->right));
    }

    void InOrderNode(const TTreeNode<T>* node, TLinkedList<int>& out) const {
        if (node == nullptr) return;
        InOrderNode(node->left, out);
        out.Append(node->key);
        InOrderNode(node->right, out);
    }

    void PreOrderNode(const TTreeNode<T>* node, TLinkedList<int>& out) const {
        if (node == nullptr) return;
        out.Append(node->key);
        PreOrderNode(node->left, out);
        PreOrderNode(node->right, out);
    }

    void PostOrderNode(const TTreeNode<T>* node, TLinkedList<int>& out) const {
        if (node == nullptr) return;
        PostOrderNode(node->left, out);
        PostOrderNode(node->right, out);
        out.Append(node->key);
    }

public:
    TBinarySearchTree() : root(nullptr), summary(new OperationSummary()) {}

    ~TBinarySearchTree() {
        DeleteSubtree(root);
    }

    bool Insert(int key, const T& value) {
        return InsertNode(root, key, value);
    }

    T* Search(int key) const {
        std::cout << "--------------BinarySearchTree--------------" << std::endl;
        resetSummary(summary);
        T* result = SearchNode(root, key);
        printSummary(summary);
        std::cout << "--------------------------------------------" << std::endl;
        return result;
    }

    bool Delete(int key) {
        return DeleteNode(root, key);
    }

    bool IsEmpty() const {
        return root == nullptr;
    }

    int Height() const {
        return HeightOf(root);
    }

    void InOrder(TLinkedList<int>& out) const {
        InOrderNode(root, out);
    }

    void PreOrder(TLinkedList<int>& out) const {
        PreOrderNode(root, out);
    }

    void PostOrder(TLinkedList<int>& out) const {
        PostOrderNode(root, out);
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

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TBINARYSEARCHTREE_H