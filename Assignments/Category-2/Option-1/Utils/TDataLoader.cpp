//
// Created by Ivan Hromovyi on 27/10/2026.
//

#include "../Utils/TDataLoader.h"
#include "StructureReader.h"

TDataLoader::TDataLoader()
    : guests(new TLinkedList<TPerson*>(true)),
        employees(new TLinkedList<TPerson*>(true)) {
}

TDataLoader::~TDataLoader() {
    delete guests;
    delete employees;
}

bool TDataLoader::OnNameRead(const int index, const int total,
    const std::string &first, const std::string &last) {
    TPerson* person = new TPerson;

    person->firstName = first;
    person->lastName = last;
    person->cabinSize = rand() % 4 + 1;

    if (index < EMPLOYEE_COUNT) {
        person->status = Status::EMPLOYEE;
        employees->Append(person);
    } else {
        person->status = Status::GUEST;
        guests->Append(person);
    }

    return true;
}

TLinkedList<TPerson*>* TDataLoader::GetGuests() const {
    return guests;
}

TLinkedList<TPerson*>* TDataLoader::GetEmployees() const {
    return employees;
}

void TDataLoader::DataInit() {
    srand(static_cast<unsigned>(time(nullptr)));
    ReadNamesFromFile(this, &TDataLoader::OnNameRead);
}
