//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TextView.h"

#include <iostream>

TextView::TextView()
    : textController(new TextController()) {}

TextView::~TextView() {
    delete textController;
}

void TextView::generateMenu() {
    int choice = -1;
    while (choice != 0) {
        std::cout << "Document Management System" << std::endl;
        std::cout << "1. Add line at end" << std::endl;
        std::cout << "2. Insert line at position" << std::endl;
        std::cout << "3. Delete line" << std::endl;
        std::cout << "4. Display text (forward)" << std::endl;
        std::cout << "5. Display text (reverse)" << std::endl;
        std::cout << "6. Undo" << std::endl;
        std::cout << "7. Redo" << std::endl;
        std::cout << "8. Print document (add to print queue)" << std::endl;
        std::cout << "9. Process next print job" << std::endl;
        std::cout << "10. Save to file" << std::endl;
        std::cout << "11. Get from file" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> choice;

        switch (choice) {
            case 1:
                textController->AppendLine();
                break;
            case 2:
                if (!textController->InsertLineAtIndex()) {
                    std::cout << "An error has occurred (id was not found)" << std::endl;
                }
                break;
            case 3:
                if (!textController->DeleteLine()) {
                    std::cout << "An error has occurred (id was not found)" << std::endl;
                }
                break;
            case 4:
                textController->Display();
                break;
            case 5:
                textController->DisplayReverse();
                break;
            case 6:
                if (!textController->Undo()) {
                    std::cout << "No action inside the undo stack" << std::endl;
                }
                break;
            case 7:
                if (!textController->Redo()) {
                    std::cout << "No action inside the redo stack" << std::endl;
                }
                break;
            case 8:
                textController->Print();
                break;
            case 9:
                textController->ProcessPrintJob();
                break;
            case 10:
                if (!textController->SaveToFile()) {
                    std::cout << "Could not find the file" << std::endl;
                }
                break;
            case 11:
                if (!textController->LoadFromFile()) {
                    std::cout << "Could not find the file" << std::endl;
                }
                break;
            case 0: break;
            default:
                std::cout << "Invalid choice : " << choice << std::endl;
        }
    }
}
