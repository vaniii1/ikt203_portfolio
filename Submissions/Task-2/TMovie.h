//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef LINKED_LIST_TMOVIE_H
#define LINKED_LIST_TMOVIE_H

#include <string>

enum EMovieGenreType {
    ACTION = 1 << 0,
    COMEDY = 1 << 1,
    DRAMA = 1 << 2,
    HORROR = 1 << 3,
    FANTASY = 1 << 4,
    ROMANCE = 1 << 5,
    THRILLER = 1 << 6
};

class TMovie {
    public:

    std::string GetTitle() const;
    std::string GetDirector() const;
    int GetYear() const;
    int GetGenreFlags() const;
    std::string GetGenre() const;
    float GetScore() const;
    std::string ToString() const;

    TMovie(std::string t, std::string d, int y, int g, float s);

    private:
    std::string title;
    std::string director;
    int year;
    int genreFlags;
    float score;
};
#endif //LINKED_LIST_TMOVIE_H