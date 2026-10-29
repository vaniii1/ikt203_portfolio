//
// Created by Ivan Hromovyi on 01/09/2026.
//

#include "TMovieController.h"

#include <iostream>

TMovieController::TMovieController(TMovieList *movieList)
    : movieList(movieList) {
    searchController = new SearchController(movieList);
}

void TMovieController::SeedMovies() {
    movieList->Append(new TMovie("The Matrix", "The Wachowskis", 1999, ACTION , 8.7f));
    movieList->Append(new TMovie("Inception", "Christopher Nolan", 2010, ACTION | THRILLER, 8.8f));
    movieList->Append(new TMovie("The Shawshank Redemption", "Frank Darabont", 1994, DRAMA, 9.3f));
    movieList->Append(new TMovie("Pulp Fiction", "Quentin Tarantino", 1994, DRAMA | THRILLER, 8.9f));
    movieList->Append(new TMovie("The Hangover", "Todd Phillips", 2009, COMEDY, 7.7f));
    movieList->Append(new TMovie("Get Out", "Jordan Peele", 2017, HORROR | THRILLER, 7.7f));
    movieList->Append(new TMovie("The Conjuring", "James Wan", 2013, HORROR, 7.5f));
    movieList->Append(new TMovie("The Lord of the Rings: The Fellowship of the Ring", "Peter Jackson", 2001, FANTASY | ACTION, 8.9f));
    movieList->Append(new TMovie("The Princess Bride", "Rob Reiner", 1987, FANTASY | ROMANCE | COMEDY, 8.0f));
    movieList->Append(new TMovie("Titanic", "James Cameron", 1997, ROMANCE | DRAMA, 7.9f));
    movieList->Append(new TMovie("Die Hard", "John McTiernan", 1988, ACTION | THRILLER, 8.2f));
    movieList->Append(new TMovie("Superbad", "Greg Mottola", 2007, COMEDY, 7.6f));
    movieList->Append(new TMovie("Alien", "Ridley Scott", 1979, HORROR , 8.5f));
    movieList->Append(new TMovie("Forrest Gump", "Robert Zemeckis", 1994, DRAMA | ROMANCE | COMEDY, 8.8f));
    movieList->Append(new TMovie("Se7en", "David Fincher", 1995, THRILLER | DRAMA, 8.6f));

    std::cout << "15 movies added to the list." << std::endl;
    movieList->PrintAll();
}

void TMovieController::Append() {
    TMovie *movie = new TMovie(
        AskUserForTitle(),
        AskUserForDirector(),
        AskUserForYear(),
        AskUserForGenreFlags(),
        AskUserForScore());

    movieList->Append(movie);
    std::cout << "Movie added: " << movie->ToString() << std::endl;
}

void TMovieController::Prepend() {
    TMovie *movie = new TMovie(
        AskUserForTitle(),
        AskUserForDirector(),
        AskUserForYear(),
        AskUserForGenreFlags(),
        AskUserForScore());

    movieList->Prepend(movie);
    std::cout << "Movie added: " << movie->ToString() << std::endl;
}

void TMovieController::GetAll() {
    std::cout << "Movie List: " << std::endl;
    movieList->PrintAll();
}

void TMovieController::GetByIndex() {
    int index = AskUserForListIndex();
    std::cout << "Movie by index : " << index << std::endl;
    std::cout << movieList->GetAtIndex(index)->ToString() << std::endl;
}

void TMovieController::RemoveByIndex() {
    int index = AskUserForListIndex();
    std::cout << movieList->Remove(index) << std::endl;
}

void TMovieController::Reverse() {
    movieList->Reverse();
    std::cout << "Reversed list : " << std::endl;
    movieList->PrintAll();
}

void TMovieController::SearchFor() {
    searchController->PrintSearchMenu();
}

std::string TMovieController::AskUserForTitle() {
    std::cout << "Enter movie title : " << std::endl;
    std::string title;
    std::getline(std::cin >> std::ws, title);
    return title;
}

std::string TMovieController::AskUserForDirector() {
    std::cout << "Enter movie director : " << std::endl;
    std::string director;
    std::getline(std::cin >> std::ws, director);
    return director;
}

int TMovieController::AskUserForYear() {
    std::cout << "Enter movie year : " << std::endl;
    int year;
    std::cin >> year;
    return year;
}

int TMovieController::AskUserForGenreFlags() {
    int genreFlags = 0;
    int choice = -1;

    while (choice != 8) {
        std::cout << "Select genres :" << std::endl;
        std::cout << "1. Action" << std::endl;
        std::cout << "2. Comedy" << std::endl;
        std::cout << "3. Drama" << std::endl;
        std::cout << "4. Horror" << std::endl;
        std::cout << "5. Fantasy" << std::endl;
        std::cout << "6. Romance" << std::endl;
        std::cout << "7. Thriller" << std::endl;
        std::cout << "8. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1: genreFlags |= ACTION;   break;
            case 2: genreFlags |= COMEDY;   break;
            case 3: genreFlags |= DRAMA;    break;
            case 4: genreFlags |= HORROR;   break;
            case 5: genreFlags |= FANTASY;  break;
            case 6: genreFlags |= ROMANCE;  break;
            case 7: genreFlags |= THRILLER; break;
            case 8: break;
            default: std::cout << "Invalid choice." << std::endl;
        }
    }

    return genreFlags;
}

float TMovieController::AskUserForScore() {
    std::cout << "Enter score : " << std::endl;
    float score;
    std::cin >> score;
    return score;
}

int TMovieController::AskUserForListIndex() {
    std::cout << "Enter list index : " << std::endl;
    int index;
    std::cin >> index;
    return index;
}

