//
// Created by Ivan Hromovyi on 27/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_TPERSON_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_TPERSON_H
#include <string>
#include <ostream>


enum class Status {
    GUEST,
    EMPLOYEE
};

inline std::string StatusToString(Status status) {
    switch (status) {
        case Status::GUEST:
            return "Guest";
        case Status::EMPLOYEE:
            return "Employee";
        default:
            return "Unknown";
    }
}

struct TPerson {
    std::string firstName;
    std::string lastName;
    Status status;
    int cabinSize;

    std::string ToString() const {
        return firstName + " " + lastName + ", status : "
            + StatusToString(status) + ", cabin : " + std::to_string(cabinSize);
    }
};

inline std::ostream& operator<<(std::ostream& result, const TPerson& aPerson) {
    return result << aPerson.ToString();
}

typedef int (*FComparePersons)(const TPerson& a, const TPerson& b);

#endif //IKT203_ALGORITHMS_DATASTRUCTURE_TPERSON_H