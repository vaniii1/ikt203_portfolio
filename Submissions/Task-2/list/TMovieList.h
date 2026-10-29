//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef LINKED_LIST_TMOVIELIST_H
#define LINKED_LIST_TMOVIELIST_H
#include "TMovieNode.h"

typedef bool (*FCheckMovie)(TMovie* movie, void* criteria);

class TMovieList {
    private:
    TMovieNode* head;
    TMovieNode* tail;
    int size;
    public:
    TMovieList();
    ~TMovieList();

    int GetSize();
    void Clear();
    void Append(TMovie* movie);
    void Prepend(TMovie* movie);
    TMovie* GetAtIndex(int index);
    bool Remove(int index);
    void Reverse();
    void PrintAll() const;

    TMovie* SearchFor(FCheckMovie function, void* criteria);
};

bool SearchByTitle(TMovie* movie, void* criteria);
bool SearchByDirector(TMovie* movie, void* criteria);
bool SearchByGenre(TMovie* movie, void* criteria);

#endif //LINKED_LIST_TMOVIELIST_H