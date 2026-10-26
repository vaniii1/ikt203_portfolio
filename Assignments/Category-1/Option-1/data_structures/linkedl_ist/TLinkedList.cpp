//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TLinkedList.h"
#include "TNode.h"

#include <iostream>
#include <ostream>

TLinkedList::TLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}

TLinkedList::~TLinkedList() {
    Clear();
}

int TLinkedList::GetSize() {
    return size;
}

void TLinkedList::Clear() {
    TNode* cur = head;
    while (cur) {
        TNode* nodeToDelete = cur;
        cur = cur->next;
        delete nodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void TLinkedList::Append(const std::string& line) {
    TNode* newNode = new TNode(line);
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

void TLinkedList::Prepend(const std::string& line) {
    TNode* newNode = new TNode(line);
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

bool TLinkedList::InsertAtIndex(int index, const std::string &line) {
    if (index < 0 || index > size) {
        return false;
    }
    if (index == 0) {
        Prepend(line);
        return true;
    }
    if (index == size) {
        Append(line);
        return true;
    }

    TNode* cur = head;
    for (int i = 0; i < index; i++) {
        cur = cur->next;
    }
    TNode* node = new TNode(line);
    node->prev = cur->prev;
    node->next = cur;
    cur->prev->next = node;
    cur->prev = node;
    size++;
    return true;
}

std::string* TLinkedList::GetAtIndex(int index) {
    if (index < 0 || index >= size) {
        return nullptr;
    }
    TNode* cur;
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
    return &cur->line;
}

bool TLinkedList::Remove(int index) {
    if (index < 0 || index >= size) {
        return false;
    }
    TNode* cur;
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

void TLinkedList::Reverse() {
    TNode* cur = head;
    while (cur != nullptr) {
        TNode* temp = cur->next;
        cur->next = cur->prev;
        cur->prev = temp;

        cur = temp;
    }

    TNode* temp = tail;
    tail = head;
    head = temp;
}

std::string TLinkedList::GetText() {
    std::string result;
    for (TNode* cur = head; cur != nullptr; cur = cur->next) {
        result += cur->line;
        if (cur->next != nullptr) result += "\n";
    }
    return result;
}

void TLinkedList::PrintAll() const {
    int index = 0;
    for (TNode* cur = head; cur != nullptr; cur = cur->next) {
        std::cout << index++ << ". " << cur->line << std::endl;
    }
}

void TLinkedList::PrintAllReverse() const {
    int index = size - 1;
    for (TNode* cur = tail; cur != nullptr; cur = cur->prev) {
        std::cout << index-- << ". " << cur->line << std::endl;
    }
}