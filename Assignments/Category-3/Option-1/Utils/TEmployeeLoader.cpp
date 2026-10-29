//
// Created by Ivan Hromovyi on 28/10/2026.
//

#include "TEmployeeLoader.h"
#include <set>
#include <ctime>
#include "StructureReader.h"

TEmployeeLoader::~TEmployeeLoader() {
    delete[] ids;
}

bool TEmployeeLoader::OnNameRead(
    const int index, const int total,
    const std::string& first, const std::string& last) {

    if (index >= EMPLOYEE_COUNT) {
        return false;
    }

    TEmployee employee;
    employee.employeeID = ids[index];
    employee.firstName = first;
    employee.lastName = last;

    employees.Append(employee);

    return index + 1 < EMPLOYEE_COUNT;
}

int* TEmployeeLoader::GenerateUniqueIDs() const {
    int* generatedIDs = new int[EMPLOYEE_COUNT];
    std::set<int> usedIDs;

    int count = 0;

    while (count < EMPLOYEE_COUNT) {
        int id = 1 + rand() % 10000;

        if (usedIDs.insert(id).second) {
            generatedIDs[count] = id;
            count++;
        }
    }

    return generatedIDs;
}

TLinkedList<TEmployee>& TEmployeeLoader::GetEmployees() {
    return employees;
}

void TEmployeeLoader::DataInit() {
    srand(static_cast<unsigned int>(time(nullptr)));
    employees.Clear();
    delete[] ids;
    ids = GenerateUniqueIDs();
    ReadNamesFromFile(this, &TEmployeeLoader::OnNameRead);
}
