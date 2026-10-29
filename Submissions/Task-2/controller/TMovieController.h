
//
// Created by Ivan Hromovyi on 01/09/2026.
//

#ifndef LINKED_LIST_TMOVIECONTROLLER_H
#define LINKED_LIST_TMOVIECONTROLLER_H
#include "SearchController.h"
#include "../list/TMovieList.h"


class TMovieController {
    public:
    TMovieController(TMovieList *movieList);

    void SeedMovies();
    void Append();
    void Prepend();
    void GetAll();
    void GetByIndex();
    void RemoveByIndex();
    void Reverse();
    void SearchFor();

    private:
    TMovieList *movieList;
    SearchController *searchController;

    std::string AskUserForTitle();
    std::string AskUserForDirector();
    int AskUserForYear();
    int AskUserForGenreFlags();
    float AskUserForScore();
    int AskUserForListIndex();
};


#endif //LINKED_LIST_TMOVIECONTROLLER_H