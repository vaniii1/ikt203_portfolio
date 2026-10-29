//
// Created by Ivan Hromovyi on 17/09/2026.
//

#include "TBankAccount.h"

#include <utility>

TBankAccount::TBankAccount(std::string accountNumber,
    EBankAccountType accountType,
    std::string ownerFirstName,
    std::string ownerLastName,
    time_t creationTimestamp,
    double balance) :
    accountNumber(std::move(accountNumber)),
    accountType(accountType),
    ownerFirstName(std::move(ownerFirstName)),
    ownerLastName(std::move(ownerLastName)),
    creationTimestamp(creationTimestamp),
    balance(balance){
}

time_t TBankAccount::GetCreationTimestamp() const {
    return creationTimestamp;
}

std::string TBankAccount::GetAccountNumber() const {
    return accountNumber;
}

double TBankAccount::GetAccountBalance() const {
    return balance;
}

std::string TypeToString(EBankAccountType type) {
    switch (type) {
        case EBankAccountType::Checking:   return "Checking";
        case EBankAccountType::Credit: return "Credit";
        case EBankAccountType::Loan: return "Loan";
        case EBankAccountType::Pension: return "Pension";
        case EBankAccountType::Savings: return "Savings";
    }
    throw std::invalid_argument("Unknown status");
}

std::string TBankAccount::ToString() const {
    return "account number: " + this->accountNumber
        + ", account type: " + TypeToString(this->accountType)
        + ", owner first name: " + this->ownerFirstName
        + ", owner last name: " + this->ownerLastName
        + ", creation timestamp: " + std::to_string(this->creationTimestamp)
        + ", balance: " + std::to_string(this->balance);
}
