//
// Created by Ivan Hromovyi on 01/09/2026.
//

#ifndef LINKED_LIST_SEARCHMENU_H
#define LINKED_LIST_SEARCHMENU_H


class TMovieList;

class SearchController {
    public:
    SearchController(TMovieList *list);

    void PrintSearchMenu();
    private:
    TMovieList *list;

    void HandleSearchByTitle();
    void HandleSearchByDirector();
    void HandleSearchByGenre();
};


#endif //LINKED_LIST_SEARCHMENU_H