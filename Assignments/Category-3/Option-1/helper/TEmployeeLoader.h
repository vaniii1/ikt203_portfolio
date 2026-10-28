//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H
#include "../models/TEmployee.h"
#include "DataStructures/TLinkedList.hpp"
#include <vector>

class TEmployeeLoader {
private:
    const int EMPLOYEE_COUNT = 200;

    TLinkedList<TEmployee> employees;
    std::vector<int> ids;

    bool onNameRead(int index, int total,
                    const std::string& first, const std::string& last);

    std::vector<int> GenerateUniqueIDs() const;
public:
    void dataInit();
    TLinkedList<TEmployee>& getEmployees();
};



#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEELOADER_H