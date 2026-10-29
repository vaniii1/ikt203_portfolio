//
// Created by Ivan Hromovyi on 27/10/2026.
//

#include "../Utils/TDataLoader.h"
#include "StructureReader.h"

TDataLoader::TDataLoader()
    : guests(new TLinkedList<TPerson>), employees(new TLinkedList<TPerson>) {
}

TDataLoader::~TDataLoader() {
    delete guests;
    delete employees;
}

bool TDataLoader::OnNameRead(const int index, const int total,
    const std::string &first, const std::string &last) {
    TPerson p;
    p.firstName = first;
    p.lastName = last;
    p.cabinSize = rand() % 4 + 1;

    if (index < EMPLOYEE_COUNT) {
        p.status = Status::EMPLOYEE;
        employees->Append(p);
    } else {
        p.status = Status::GUEST;
        guests->Append(p);
    }
    return true;
}

TLinkedList<TPerson>* TDataLoader::GetGuests() const {
    return guests;
}

TLinkedList<TPerson>* TDataLoader::GetEmployees() const {
    return employees;
}

void TDataLoader::DataInit() {
    srand(static_cast<unsigned>(time(nullptr)));
    ReadNamesFromFile(this, &TDataLoader::OnNameRead);
}
