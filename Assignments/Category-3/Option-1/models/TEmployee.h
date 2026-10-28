//
// Created by Ivan Hromovyi on 28/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEE_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEE_H
#include <string>

struct TEmployee {
    int employeeID;
    std::string firstName;
    std::string lastName;

    std::string ToString() const {
        return firstName + " " + lastName + ", employeeID : " + std::to_string(employeeID);
    }
};

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TEMPLOYEE_H
