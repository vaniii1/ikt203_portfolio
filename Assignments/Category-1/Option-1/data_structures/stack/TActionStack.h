//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TUNDOSTACK_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TUNDOSTACK_H
#include <string>

enum class ActionType { INSERT_LINE, DELETE_LINE };

struct TAction {
    ActionType type;
    int index;
    std::string text;
};

const int MAX_SIZE_STACK = 20;

class TActionStack {
        TAction* arr[MAX_SIZE_STACK];
        int bottom = 0;
        int count = 0;
    public:
        TActionStack();
        ~TActionStack();
        void Push(TAction *action);
        TAction* Pop();
        bool IsEmpty();
        void Clear();
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TUNDOSTACK_H