//
// Created by Ivan Hromovyi on 01/09/2026.
//

#include "TMovieMenu.h"

#include <iostream>

TMovieMenu::TMovieMenu(TMovieController *controller)
    : controller(controller) {
}

void TMovieMenu::GenerateMenu() {
    int choice = -1;

    while (choice != 8) {
        std::cout << "Movie List Menu" << std::endl;
        std::cout << std::endl;
        std::cout << "1. Append movie" << std::endl;
        std::cout << "2. Prepend movie" << std::endl;
        std::cout << "3. Get all movies" << std::endl;
        std::cout << "4. Get movie by index" << std::endl;
        std::cout << "5. Remove movie by index" << std::endl;
        std::cout << "6. Reverse list" << std::endl;
        std::cout << "7. Search by" << std::endl;
        std::cout << "8. Exit" << std::endl;

        std::cin >> choice;
        switch (choice) {
            case 1:
                controller->Append();
                break;
            case 2:
                controller->Prepend();
                break;
            case 3:
                controller->GetAll();
                break;
            case 4:
                controller->GetByIndex();
                break;
            case 5:
                controller->RemoveByIndex();
                break;
            case 6:
                controller->Reverse();
                break;
            case 7:
                controller->SearchFor();
                break;
            case 8: break;
            default: std::cout << "Invalid choice : " << choice << std::endl;
        }
    }
}
