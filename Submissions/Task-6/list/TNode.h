//
// Created by Ivan Hromovyi on 17/09/2026.
//

#ifndef BANKING_SYSTEM_SIMPLE_SEARCH_TNODE_H
#define BANKING_SYSTEM_SIMPLE_SEARCH_TNODE_H
#include "../TBankAccount.h"


class TNode {
public:
    TNode(TBankAccount* bankAccount);

    TBankAccount *account;
    TNode* next;
    TNode* prev;
};

#endif //BANKING_SYSTEM_SIMPLE_SEARCH_TNODE_H