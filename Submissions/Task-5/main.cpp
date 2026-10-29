#include <iostream>

#include "TBankAccount.h"
#include "list/ListInit.h"
#include "list/TLinkedList.h"

TBankAccount* FindAccountByNumber(TBankAccount** accountArray, int arraySize,
                                  const std::string& accountNumber, SearchSummary& summary) {
    resetSummary(&summary);
    TBankAccount* result = nullptr;
    for (int i = 0; i < arraySize; i++) {
        summary.comparisons++;
        if (accountArray[i]->GetAccountNumber() == accountNumber) {
            result = accountArray[i];
            break;
        }
    }
    printSummary(&summary);
    return result;
}

void PrintEveryAccountInDateRange(TBankAccount** accountArray, int arraySize,
                                   time_t fromDate, time_t toDate, SearchSummary& summary) {
    resetSummary(&summary);
    int count = 0;
    for (int i = 0; i < arraySize; i++) {
        summary.comparisons++;
        time_t t = accountArray[i]->GetCreationTimestamp();
        if (t >= fromDate && t <= toDate) {
            std::cout << std::to_string(count++) << ". " << accountArray[i]->ToString() << std::endl;
        }
    }
    printSummary(&summary);
}

time_t MakeTimestamp(int year, int month, int day, int hour) {
    tm parts = {};
    parts.tm_year = year - 1900;
    parts.tm_mon = month - 1;
    parts.tm_mday = day;
    parts.tm_hour = hour;
    return mktime(&parts);
}

int main() {
    srand((unsigned)time(nullptr));
    int size = 5000;
    TBankAccount** accountArray = nullptr;

    SearchSummary listSummary;
    SearchSummary arraySummary;

    TLinkedList list(true, &listSummary);

    // populating the data
    ListInit::Populate(list, accountArray, size);

    // find account by account number
    TBankAccount *accountByNumber = FindAccountByNumber(accountArray, size,
                              "ACC10", arraySummary);
    if (accountByNumber != nullptr) {
        std::cout << accountByNumber->ToString() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    // date range from to
    time_t fromDate = MakeTimestamp(2024, 1, 1, 0);
    time_t toDate = MakeTimestamp(2024, 1, 1, 12);
    // get every account within the given date
    PrintEveryAccountInDateRange(accountArray, size, fromDate, toDate, arraySummary);
    std::cout << "--------------------------------" << std::endl;

    // find account near to the front of the list
    std::string nearFrontAccountNumberKey = "ACC9";
    TBankAccount* nearFrontAccount = list.Find(
        CompareByAccountNumber, &nearFrontAccountNumberKey);
    if (nearFrontAccount != nullptr) {
        std::cout << nearFrontAccount->ToString() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    // find account near to the end of the list
    std::string nearEndAccountNumberKey = "ACC4900" ;
    TBankAccount* nearEnd = list.Find(CompareByAccountNumber, &nearEndAccountNumberKey);
    if (nearEnd != nullptr) {
        std::cout << nearEnd->ToString() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    // search account that does not exist
    std::string nonExistentAccountNumberKey = "NO_ACC";
    TBankAccount* nonExistentAccount = list.Find(
        CompareByAccountNumber, &nonExistentAccountNumberKey);
    if (nonExistentAccount != nullptr) {
        std::cout << nonExistentAccount->ToString() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;

    // find all integrated every account created in June 2024
    int june = 5;
    TLinkedList* juneAccounts = list.Every(CompareByCreationMonth, &june);
    std::cout << "Accounts created in June 2024 : " << std::endl;
    juneAccounts->PrintAll();
    delete juneAccounts;
    std::cout << "--------------------------------" << std::endl;

    fromDate = MakeTimestamp(2024, 1, 1, 0);
    toDate = MakeTimestamp(2024, 4, 1, 0) - 1;
    std::cout << "Accounts created in the first quarter of 2024 : " << std::endl;
    PrintEveryAccountInDateRange(accountArray, size, fromDate, toDate,
        arraySummary);
    std::cout << "--------------------------------" << std::endl;
    delete[] accountArray;
    return 0;
}

// report can be found in /resources/report_assignment5_ikt203_ivanh.pdf
