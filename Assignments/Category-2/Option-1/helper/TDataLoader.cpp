//
// Created by Ivan Hromovyi on 27/10/2026.
//

#include "TDataLoader.h"
#include "StructureReader.h"

TDataLoader::TDataLoader()
    : guests(new TLinkedList<TPerson>), employees(new TLinkedList<TPerson>) {
}

TDataLoader::~TDataLoader() {
    delete guests;
    delete employees;
}

bool TDataLoader::onNameRead(const int index, const int total,
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

TLinkedList<TPerson>* TDataLoader::getGuests() const {
    return guests;
}

TLinkedList<TPerson>* TDataLoader::getEmployees() const {
    return employees;
}

void TDataLoader::dataInit() {
    srand(static_cast<unsigned>(time(nullptr)));
    ReadNamesFromFile(this, &TDataLoader::onNameRead);
}
