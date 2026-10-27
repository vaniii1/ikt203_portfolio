//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TEXTCONTROLLER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TEXTCONTROLLER_H

#include "DataStructures/TStack.hpp"
#include "DataStructures/TLinkedList.hpp"
#include "DataStructures/TQueue.hpp"
#include "../models/TAction.h"
#include "../models/TJob.h"
#include <string>

class TextController {
private:
    TLinkedList<std::string>* linkedList;
    TStack<TAction>* redoStack;
    TStack<TAction>* undoStack;
    TQueue<TJob>* queue;
    int nextJobIndex = 0;

    int askUserForIndex();
    std::string askUserForFilePath();
    std::string askUserForTextLine();

    public:
    TextController();
    ~TextController();

    void Print();
    void ProcessPrintJob();

    void AppendLine();

    bool InsertLineAtIndex();
    bool DeleteLine();
    bool Undo();
    bool Redo();
    int GetLineCount();
    void Display();
    void DisplayReverse();
    bool LoadFromFile();
    bool SaveToFile();
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TEXTCONTROLLER_H