//
// Created by Ivan Hromovyi on 31/08/2026.
//

#include "TMovie.h"
#include <utility>

static std::string GenreFlagsToString(int genreFlags) {
    std::string result;
    if (genreFlags & ACTION) result += "Action ";
    if (genreFlags & COMEDY) result += "Comedy ";
    if (genreFlags & DRAMA) result += "Drama ";
    if (genreFlags & HORROR) result += "Horror ";
    if (genreFlags & FANTASY) result += "Fantasy ";
    if (genreFlags & ROMANCE) result += "Romance ";
    if (genreFlags & THRILLER) result += "Thriller ";
    return result.empty() ? "None" : result;
}

std::string TMovie::GetTitle() const {
    return this->title;
}

std::string TMovie::GetDirector() const {
    return this->director;
}

int TMovie::GetYear() const {
    return this->year;
}

int TMovie::GetGenreFlags() const {
    return this->genreFlags;
}

std::string TMovie::GetGenre() const {
    return GenreFlagsToString(this->genreFlags);
}

float TMovie::GetScore() const {
    return this->score;
}

std::string TMovie::ToString() const {
    return "title: " + this->title + ", director: " + this->director
        + ", year: " + std::to_string(this->year) + ", genre: " + this->GetGenre()
        + ", score: " + std::to_string(this->score);
}

TMovie::TMovie(std::string t, std::string d, int y, int g, float s)
    : title(std::move(t)), director(std::move(d)),
    year(y), genreFlags(g), score(s) {}
