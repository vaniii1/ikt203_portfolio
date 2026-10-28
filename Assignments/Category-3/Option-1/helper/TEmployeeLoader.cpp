//
// Created by Ivan Hromovyi on 28/10/2026.
//

#include "TEmployeeLoader.h"
#include <set>
#include <ctime>
#include "StructureReader.h"

bool TEmployeeLoader::onNameRead(const int index, const int total,
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

std::vector<int> TEmployeeLoader::GenerateUniqueIDs() const {
    std::vector<int> ids;
    std::set<int> usedIDs;

    while (ids.size() < EMPLOYEE_COUNT) {
        int id = 1 + rand() % 10000;

        if (usedIDs.insert(id).second) {
            ids.push_back(id);
        }
    }
    return ids;
}

TLinkedList<TEmployee>& TEmployeeLoader::getEmployees() {
    return employees;
}

void TEmployeeLoader::dataInit() {
    srand(static_cast<unsigned int>(time(nullptr)));
    employees.Clear();
    ids = GenerateUniqueIDs();
    ReadNamesFromFile(this, &TEmployeeLoader::onNameRead);
}