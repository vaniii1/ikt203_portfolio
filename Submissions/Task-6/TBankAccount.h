//
// Created by Ivan Hromovyi on 17/09/2026.
//

#ifndef BANKING_SYSTEM_SIMPLE_SEARCH_TBANKACCOUNT_H
#define BANKING_SYSTEM_SIMPLE_SEARCH_TBANKACCOUNT_H
#include <string>

enum class EBankAccountType {
    Checking,
    Savings,
    Credit,
    Pension,
    Loan
};

class TBankAccount {
public:
    TBankAccount(std::string accountNumber,
        EBankAccountType accountType,
        std::string ownerFirstName,
        std::string ownerLastName,
        time_t creationTimestamp,
        double balance);

    time_t GetCreationTimestamp() const;
    std::string GetAccountNumber() const;
    std::string GetOwnerLastName() const;
    std::string ToString() const;
    double GetBalance() const;

private:
    std::string accountNumber;
    EBankAccountType accountType;
    std::string ownerFirstName;
    std::string ownerLastName;
    time_t creationTimestamp;
    double balance;
};


#endif //BANKING_SYSTEM_SIMPLE_SEARCH_TBANKACCOUNT_H