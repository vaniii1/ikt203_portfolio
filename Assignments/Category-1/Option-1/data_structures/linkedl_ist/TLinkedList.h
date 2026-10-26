//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TLINKEDLIST_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TLINKEDLIST_H

#include <string>
#include "TNode.h"


class TLinkedList {
private:
    TNode* head;
    TNode* tail;
    int size;
public:
    TLinkedList();
    ~TLinkedList();

    int GetSize();
    void Clear();
    void Append(const std::string& line);
    void Prepend(const std::string& line);
    bool InsertAtIndex(int index, const std::string& line);
    std::string* GetAtIndex(int index);
    bool Remove(int index);
    void Reverse();
    std::string GetText();
    void PrintAll() const;
    void PrintAllReverse() const;
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TLINKEDLIST_H