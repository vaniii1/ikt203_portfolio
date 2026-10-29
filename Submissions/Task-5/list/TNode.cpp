//
// Created by Ivan Hromovyi on 17/09/2026.
//

#include "TNode.h"

TNode::TNode(TBankAccount *account)
    : account(account), next(nullptr), prev(nullptr) {
}
