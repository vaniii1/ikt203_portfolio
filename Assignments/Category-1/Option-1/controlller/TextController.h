//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTCONTROLLER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTCONTROLLER_H
#include "../data_structures/linkedl_ist/TLinkedList.h"
#include "../data_structures/queue/TQueue.h"
#include "../data_structures/stack/TActionStack.h"


class TextController {
private:
    TLinkedList* linkedList;
    TActionStack* redoStack;
    TActionStack* undoStack;
    TQueue* queue;
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


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTCONTROLLER_H