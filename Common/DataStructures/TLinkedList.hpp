#pragma once
#include <stdexcept> // For std::runtime_error
#include <string>    // For std::to_string
#include <functional> // For std::function
#include "../DebugUtils.h" // For debugText function
#include "TCollection.hpp" // Your base collection class
#include "TNode.hpp" // Your node class
#include <iostream>
#include <sstream>

/**
* @file   TLinkedList.hpp
* @brief  Dear student, this file contains the definition of the TLinkedList class template, which serves as a doubly-linked list implementation for storing elements of type T.
*					You will create this as a template class typically holding methods for appending, prepending, searching, and iterating over elements.
*					Type of linked list is op to you, you must clean (delete) your data yourself so be wize about the type of T you choose to use.
*         I recommend to implenet a "isOwner" boolean variable to determine if the list is responsible for deleting the data or not.
*					Please ask for help in Discord if you have any questions or need assistance with the implementation.
* @tparam T The type of elements stored in the linked list.
*/


template <typename T>
class TLinkedList {
private:
    TNode<T>* head = nullptr;
    TNode<T>* tail = nullptr;
    int size = 0;

    public:
    TLinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~TLinkedList() {
        Clear();
    }

    int GetSize() {
        return size;
    }

    void Clear() {
        TNode<T>* cur = head;
        while (cur) {
            TNode<T>* nodeToDelete = cur;
            cur = cur->next;
            delete nodeToDelete;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Append(const T& data) {
        auto* newNode = new TNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void Prepend(const T& data) {
        auto* newNode = new TNode<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = head;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }

    bool InsertAtIndex(int index, const T& data) {
        if (index < 0 || index > size) {
            return false;
        }
        if (index == 0) {
            Prepend(data);
            return true;
        }
        if (index == size) {
            Append(data);
            return true;
        }

        TNode<T>* cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        TNode<T>* node = new TNode(data);
        node->prev = cur->prev;
        node->next = cur;
        cur->prev->next = node;
        cur->prev = node;
        size++;
        return true;
    }

    T* GetAtIndex(int index) {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        TNode<T>* cur;
        int halfSize = size / 2;
        if (index < halfSize) {
            cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (int i = size - 1; i > index; i--) {
                cur = cur->prev;
            }
        }
        return &cur->data;
    }

    bool Remove(int index) {
        if (index < 0 || index >= size) {
            return false;
        }
        TNode<T>* cur;
        if (index < size / 2) {
            cur = head;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
        } else {
            cur = tail;
            for (int i = size - 1; i > index; i--) {
                cur = cur->prev;
            }
        }
        if (cur->prev == nullptr) {
            head = cur->next;
            if (head != nullptr) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
        } else if (cur->next == nullptr) {
            tail = cur->prev;
            tail->next = nullptr;
        } else {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        size--;
        return true;
    }

    void Reverse() {
        TNode<T>* cur = head;
        while (cur != nullptr) {
            TNode<T>* temp = cur->next;
            cur->next = cur->prev;
            cur->prev = temp;

            cur = temp;
        }

        TNode<T>* temp = tail;
        tail = head;
        head = temp;
    }

    std::string GetText() {
        std::string result;
        for (TNode<T>* cur = head; cur != nullptr; cur = cur->next) {
            result += cur->data;
            if (cur->next != nullptr) result += "\n";
        }
        return result;
    }

    void PrintAll() const {
        int index = 0;
        for (TNode<T>* cur = head; cur != nullptr; cur = cur->next) {
            std::cout << index++ << ". " << cur->data << std::endl;
        }
    }

    void PrintAllReverse() const {
        int index = size - 1;
        for (TNode<T>* cur = tail; cur != nullptr; cur = cur->prev) {
            std::cout << index-- << ". " << cur->data << std::endl;
        }
    }
};

