//
// Created by Ivan Hromovyi on 27/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H
#include "../models/TPerson.h"
#include "DataStructures/TLinkedList.hpp"


class TDataLoader {
private:
    const int EMPLOYEE_COUNT = 1500;

    TLinkedList<TPerson> *guests;
    TLinkedList<TPerson> *employees;
    bool onNameRead(const int index, const int total,
                const std::string& first, const std::string& last);
public:

    TLinkedList<TPerson>* getGuests() const;
    TLinkedList<TPerson>* getEmployees() const;

    TDataLoader();

    ~TDataLoader();

    void dataInit();

};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H