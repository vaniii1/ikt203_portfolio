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
class TLinkedList : public TCollection<T> {
private:
    TNode<T>* head = nullptr;
    TNode<T>* tail = nullptr;
    int size = 0;
    bool isDataOwner;

    public:
    TLinkedList(bool isDataOwner = false) : isDataOwner(isDataOwner) {}

    ~TLinkedList() {
        Clear();
    }

    TNode<T>* GetHead() const {
        return head;
    }

    TNode<T>* GetTail() const {
        return tail;
    }

    void SetHead(TNode<T>* newHead) {
        head = newHead;
    }

    void SetTail(TNode<T>* newTail) {
        tail = newTail;
    }
    int GetSize() const override {
        return size;
    }

    bool IsEmpty() const override {
        return size == 0;
    }

    void Clear() override {
        TNode<T>* current = head;
        while (current != nullptr) {
            TNode<T>* nodeToDelete = current;
            current = current->next;
            if constexpr (std::is_pointer_v<T>) {
                if (isDataOwner) {
                    delete nodeToDelete->data;
                }
            }
            delete nodeToDelete;
        }
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void Append(const T& data) {
        TNode<T>* newNode = new TNode<T>(data);
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
        TNode<T>* newNode = new TNode(data);
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
            throw std::runtime_error("index out of bounds");
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

    T GetAtIndex(int index) {
        if (index < 0 || index >= size) {
            throw std::runtime_error("index out of bounds");
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
        return cur->data;
    }

    T Remove(int index) {
        if (index < 0 || index >= size) {
            throw std::runtime_error("index out of bounds");
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

        if (cur->prev) {
            cur->prev->next = cur->next;
        } else {
            head = cur->next;
        }
        if (cur->next) {
            cur->next->prev = cur->prev;
        } else {
            tail = cur->prev;
        }

        T data = cur->data;
        delete cur;
        size--;
        return data;
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

    std::string GetText() const {
        std::ostringstream result;
        for (TNode<T>* cur = head; cur != nullptr; cur = cur->next) {
            result << cur->data;
            if (cur->next != nullptr) result << "\n";
        }
        return result.str();
    }

    void PrintFirst10() const {
        int index = 0;
        for (TNode<T>* cur = head; cur != nullptr && index < 10;
         cur = cur->next) {
            std::cout << index++ << ". ";
            if constexpr (std::is_pointer_v<T>) {
                if (cur->data != nullptr)
                    std::cout << *cur->data;
            } else {
                std::cout << cur->data;
            }
            std::cout << std::endl;
         }
    }

    void PrintAll() const {
        int index = 0;
        for (TNode<T>* cur = head; cur != nullptr; cur = cur->next) {
            std::cout << index++ << ". ";
            if constexpr (std::is_pointer_v<T>) {
                if (cur->data != nullptr)
                    std::cout << *cur->data;
            } else {
                std::cout << cur->data;
            }
            std::cout << std::endl;
         }
    }

    void PrintAllReverse() const {
        int index = size - 1;
        for (TNode<T>* cur = tail; cur != nullptr; cur = cur->prev) {
            std::cout << index-- << ". ";
            if constexpr (std::is_pointer_v<T>) {
                if (cur->data != nullptr)
                    std::cout << *cur->data;
            } else {
                std::cout << cur->data;
            }
            std::cout << std::endl;
        }
    }
};

