//
// Created by Ivan Hromovyi on 18/09/2026.
//

#include "ListInit.h"
#include <vector>
#include <string>

void ListInit::Populate(TLinkedList& list, TBankAccount**& accountArray, int minAccounts) {
    std::vector<std::string> firstNames = {
        "Kim", "Glenda", "Ivan", "Juan", "Maureen", "Sofia", "Johnny", "Amanda", "Emma",
        "Naomi", "Joyce", "Bobby", "Sergio", "Pat", "Kathy", "Nicholas", "Howard", "Gavin",
        "Jose", "Teresa", "Norman", "Felecia", "Melvin", "Lillian", "Jacob", "William",
        "Isobel", "Judith", "Alexis", "Josephine", "Chloe", "Shawn", "Julie", "Darlene",
        "Crystal", "Kelly", "Jorge", "Anne", "Letitia", "Rosa", "Ronald", "Dale", "Frederick",
        "Larry", "Ellen", "Lewis", "Amelia", "Connor", "Dwayne", "Tara", "Andrea", "Albert",
    };
    std::vector<std::string> lastNames = {
        "Price", "Herrera", "Meyer", "Mitchelle", "Smith", "Williams", "Bradley", "Powell",
        "Hoffman", "Campbell", "Little", "Jensen", "Berry", "Simmons", "Dixon", "Watson",
        "Mcdonalid", "Stanley", "Ruiz", "Curtis", "Willis", "Holland", "Kuhn", "Brown",
        "Thomas", "Wilson", "Sanchez", "Ortiz", "Andrews", "Carlson", "White", "Clark",
        "Grant", "Flores", "Long", "Shelton", "George", "Fields", "Warren", "Reed", "Morgan",
        "Arnold", "Lawson", "Caldwell", "Evans", "Marshall", "Reynolds", "Brooks", "Elliott",
    };
    accountArray = new TBankAccount*[minAccounts];
    int index = 0;
    while (list.GetSize() < minAccounts) {
        std::string firstName = firstNames[rand() % firstNames.size()];
        std::string lastName  = lastNames[rand() % lastNames.size()];
        int accountsForThisPerson = 5 + rand() % 6; // 5 to 10 accounts per person

        for (int j = 0; j < accountsForThisPerson; j++) {
            if (list.GetSize() == minAccounts) {
                return;
            }
            int typeIndex = rand() % 5;

            // generate random type
            EBankAccountType type = static_cast<EBankAccountType>(typeIndex);
            std::string accountNumber = "ACC" + std::to_string(index);

            // generate random balance based on account type
            double balance = 0.0;
            if (type == EBankAccountType::Loan)
                balance = -50000 + (rand() % 25001);
            else if (type == EBankAccountType::Credit)
                balance = -1000 + (rand() % 1001);
            else
                balance = rand() % 1001;

            // generate random date within the 2024
            tm t = {};
            t.tm_year = 124;
            t.tm_mon  = rand() % 12;
            t.tm_mday = 1 + rand() % 28;
            t.tm_hour = rand() % 24;
            t.tm_min  = rand() % 60;
            t.tm_sec  = rand() % 60;
            time_t creationTimestamp = mktime(&t);

            TBankAccount* acc = new TBankAccount(accountNumber, type, firstName,
                lastName, creationTimestamp, balance);
            accountArray[index++] = acc;
            list.Append(acc);
        }
    }
}
