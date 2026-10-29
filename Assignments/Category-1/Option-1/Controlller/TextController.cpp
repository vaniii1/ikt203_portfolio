//
// Created by Ivan Hromovyi on 26/10/2026.
//

#include "TextController.h"
#include "../Models/TJob.h"
#include <iostream>
#include <ostream>
#include <fstream>

TextController::TextController() : linkedList(new TLinkedList<std::string>()),
    redoStack(new TStack<TAction>), undoStack(new TStack<TAction>), queue(new TQueue<TJob>) {}

TextController::~TextController() {
    delete undoStack;
    delete redoStack;
    delete linkedList;
    delete queue;
}

void TextController::Print() {
    std::cout << "-------------------------------" << std::endl;
    int index = nextJobIndex++;
    TJob *job = new TJob(index, linkedList->GetText());
    if (!queue->Enqueue(job)) {
        delete job;
        std::cout << "Print queue is full" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        return;
    }
    std::cout << "New job was added to the queue : " << index << std::endl;
    std::cout << "-------------------------------" << std::endl;
}

void TextController::ProcessPrintJob() {
    std::cout << "-------------------------------" << std::endl;
    TJob* job = queue->Dequeue();
    if (!job) {
        std::cout << "No print jobs in the queue" << std::endl;
        std::cout << "-------------------------------" << std::endl;
        return;
    }
    std::cout << "Processing job with id : " << job->index << std::endl;
    std::cout << job->text << std::endl;
    delete job;
    std::cout << "-------------------------------" << std::endl;
}

void TextController::AppendLine() {
    std::string text = askUserForTextLine();
    linkedList->Append(text);
    undoStack->Push(new TAction(ActionType::INSERT_LINE, linkedList->GetSize() - 1, text));
    redoStack->Clear();
}

bool TextController::InsertLineAtIndex() {
    int index = askUserForIndex();
    std::string text = askUserForTextLine();
    if (!linkedList->InsertAtIndex(index, text)) {
        return false;
    }
    undoStack->Push(new TAction(ActionType::INSERT_LINE, index, text));
    redoStack->Clear();
    return true;
}

bool TextController::DeleteLine() {
    int index = askUserForIndex();
    auto line = linkedList->GetAtIndex(index);
    if (!line) {
        return false;
    }

    TAction* action = new TAction{ActionType::DELETE_LINE, index, *line};
    linkedList->Remove(index);
    undoStack->Push(action);
    redoStack->Clear();
    return true;
}

bool TextController::Undo() {
    TAction* action = undoStack->Pop();
    if (!action) {
        return false;
    }

    if (action->type == ActionType::INSERT_LINE) {
        linkedList->Remove(action->index);
    } else {
        linkedList->InsertAtIndex(action->index, action->text);
    }
    redoStack->Push(action);
    return true;
}

bool TextController::Redo() {
    TAction* action = redoStack->Pop();

    if (!action) {
        return false;
    }

    if (action->type == ActionType::INSERT_LINE) {
        linkedList->InsertAtIndex(action->index, action->text);
    } else {
        linkedList->Remove(action->index);
    }
    undoStack->Push(action);
    return true;
}

int  TextController::GetLineCount() {
    return linkedList->GetSize();
}

void TextController::Display() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Display text" << std::endl;
    linkedList->PrintAll();
    std::cout << "-------------------------------" << std::endl;
}

void TextController::DisplayReverse() {
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Display text reverse" << std::endl;
    linkedList->PrintAllReverse();
    std::cout << "-------------------------------" << std::endl;
}

bool TextController::LoadFromFile() {
    std::string path = askUserForFilePath();
    std::ifstream file(path);
    if (!file.is_open()) {
        return false;
    }

    linkedList->Clear();
    undoStack->Clear();
    redoStack->Clear();

    std::string line;
    while (std::getline(file, line)) {
        linkedList->Append(line);
    }
    return true;
}

bool TextController::SaveToFile() {
    std::string path = askUserForFilePath();
    std::ofstream file(path);
    if (!file.is_open()) {
        return false;
    }

    file << linkedList->GetText();
    if (linkedList->GetSize() > 0) {
        file << std::endl;
    }
    return true;
}

std::string TextController::askUserForTextLine() {
    std::cout << "Enter new text line : " << std::endl;
    std::string line;
    std::getline(std::cin >> std::ws, line);
    return line;
}

int TextController::askUserForIndex() {
    std::cout << "Enter line index : " << std::endl;
    int index;
    std::cin >> index;
    return index;
}

std::string TextController::askUserForFilePath() {
    std::cout << "Enter file path : " << std::endl;
    std::string path;
    std::getline(std::cin >> std::ws, path);
    return path;
}