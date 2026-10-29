//
// Created by Ivan Hromovyi on 01/09/2026.
//

#include "../controller/SearchController.h"

#include <iostream>

#include "../list/TMovieList.h"

class TMovieList;

SearchController::SearchController(TMovieList *list) : list(list) {
}

void SearchController::PrintSearchMenu() {
    int choice = -1;
    while (choice != 4) {
        std::cout << "Search by :" << std::endl;
        std::cout << "1. Title" << std::endl;
        std::cout << "2. Director" << std::endl;
        std::cout << "3. Genre" << std::endl;
        std::cout << "4. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1: HandleSearchByTitle(); break;
            case 2: HandleSearchByDirector(); break;
            case 3: HandleSearchByGenre(); break;
            case 4: break;
            default: std::cout << "Invalid choice." << std::endl;
        }
    }
}

void SearchController::HandleSearchByTitle() {
    std::cout << "Enter movie title : " << std::endl;
    std::string title;
    std::getline(std::cin >> std::ws, title);

    TMovie* movie = list->SearchFor(SearchByTitle, &title);
    if (movie != nullptr) {
        std::cout << "Found: " << movie->ToString() << std::endl;
    } else {
        std::cout << "No movie found with that title." << std::endl;
    }
}

void SearchController::HandleSearchByDirector() {
    std::cout << "Enter movie director : " << std::endl;
    std::string director;
    std::getline(std::cin >> std::ws, director);

    TMovie* movie = list->SearchFor(SearchByDirector, &director);
    if (movie != nullptr) {
        std::cout << "Found: " << movie->ToString() << std::endl;
    } else {
        std::cout << "No movie found with that director." << std::endl;
    }
}

void SearchController::HandleSearchByGenre() {
    std::cout << "Select genre to search by :" << std::endl;
    std::cout << "1. Action" << std::endl;
    std::cout << "2. Comedy" << std::endl;
    std::cout << "3. Drama" << std::endl;
    std::cout << "4. Horror" << std::endl;
    std::cout << "5. Fantasy" << std::endl;
    std::cout << "6. Romance" << std::endl;
    std::cout << "7. Thriller" << std::endl;
    std::cout << "8. Exit" << std::endl;

    int choice;
    std::cin >> choice;

    int genreFlag = 0;
    switch (choice) {
        case 1: genreFlag = ACTION;   break;
        case 2: genreFlag = COMEDY;   break;
        case 3: genreFlag = DRAMA;    break;
        case 4: genreFlag = HORROR;   break;
        case 5: genreFlag = FANTASY;  break;
        case 6: genreFlag = ROMANCE;  break;
        case 7: genreFlag = THRILLER; break;
        case 8: break;
        default:
            std::cout << "Invalid choice." << std::endl;
            return;
    }

    TMovie* movie = list->SearchFor(SearchByGenre, &genreFlag);
    if (movie != nullptr) {
        std::cout << "Found: " << movie->ToString() << std::endl;
    } else {
        std::cout << "No movie found with that genre." << std::endl;
    }
}