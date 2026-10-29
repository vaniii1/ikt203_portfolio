
//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef LINKED_LIST_TMOVIENODE_H
#define LINKED_LIST_TMOVIENODE_H
#include "../TMovie.h"


class TMovieNode {
public:
    TMovieNode(TMovie* movie);
    ~TMovieNode();
    TMovie* movie;
    TMovieNode* next;
    TMovieNode* prev;
};


#endif //LINKED_LIST_TMOVIENODE_H