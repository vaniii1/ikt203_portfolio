//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TACTION_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TACTION_H
#include <string>

enum class ActionType { INSERT_LINE, DELETE_LINE };

struct TAction {
    ActionType type;
    int index;
    std::string text;

    TAction(ActionType type, int index, std::string text)
        : type(type), index(index), text(std::move(text)) {};
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TACTION_H