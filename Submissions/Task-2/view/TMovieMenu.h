//
// Created by Ivan Hromovyi on 01/09/2026.
//

#ifndef LINKED_LIST_TMOVIEMENU_H
#define LINKED_LIST_TMOVIEMENU_H
#include "../controller/TMovieController.h"

class SearchController;

class TMovieMenu {
    public:
    TMovieMenu(TMovieController *controller);

    void GenerateMenu();
    private:
    TMovieController *controller;
};


#endif //LINKED_LIST_TMOVIEMENU_H