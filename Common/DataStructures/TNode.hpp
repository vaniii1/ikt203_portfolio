/**
* @file TNode.hpp
* @brief  Dear student, this file contains the definition of the TNode class template, which serves as a node in a doubly-linked list implementation for storing elements of type T.
*					You will create this as a template class typically holding data of type T and pointers to other nodes in the list. (you must choose if this is singel or double linked list)
*					Please ask for help in Discord if you have any questions or need assistance with the implementation.
*/

#pragma once

template <typename T>
class TLinkedList;

template <typename T>
class TNode {
public:
    T data;
    TNode* next;
    TNode* prev;
    explicit TNode(const T& data) : data(data), next(nullptr), prev(nullptr) {}
};
