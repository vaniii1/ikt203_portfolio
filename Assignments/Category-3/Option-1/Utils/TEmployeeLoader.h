//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H

#include "../Models/TEmployee.h"
#include "DataStructures/TLinkedList.hpp"

class TEmployeeLoader {
private:
    const int EMPLOYEE_COUNT = 200;

    TLinkedList<TEmployee> employees;
    int* ids = nullptr;

    bool OnNameRead(int index, int total,
                    const std::string& first, const std::string& last);

    int* GenerateUniqueIDs() const;
public:
    TEmployeeLoader() = default;
    ~TEmployeeLoader();

    TEmployeeLoader(const TEmployeeLoader&) = delete;
    TEmployeeLoader& operator=(const TEmployeeLoader&) = delete;

    void DataInit();
    TLinkedList<TEmployee>& GetEmployees();
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H