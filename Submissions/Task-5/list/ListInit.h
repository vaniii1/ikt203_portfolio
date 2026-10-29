//
// Created by Ivan Hromovyi on 18/09/2026.
//

#ifndef BANKING_SYSTEM_SIMPLE_SEARCH_LISTINIT_H
#define BANKING_SYSTEM_SIMPLE_SEARCH_LISTINIT_H
#include "TLinkedList.h"


class ListInit {
public:
    // Populates list with at least minAccounts TBankAccount objects (5-10 per person)
    static void Populate(TLinkedList& list, TBankAccount**& accountArray, int minAccounts);
};

#endif //BANKING_SYSTEM_SIMPLE_SEARCH_LISTINIT_H