//
// Created by Ivan Hromovyi on 27/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H
#include "../Models/TPerson.h"
#include "DataStructures/TLinkedList.hpp"


class TDataLoader {
private:
    const int EMPLOYEE_COUNT = 1500;

    TLinkedList<TPerson> *guests;
    TLinkedList<TPerson> *employees;
    bool OnNameRead(const int index, const int total,
                const std::string& first, const std::string& last);
public:

    TLinkedList<TPerson>* GetGuests() const;
    TLinkedList<TPerson>* GetEmployees() const;

    TDataLoader();

    ~TDataLoader();

    void DataInit();

};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_DATACONTROLLER_H