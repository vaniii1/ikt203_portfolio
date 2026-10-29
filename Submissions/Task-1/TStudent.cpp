//
// Created by Ivan Hromovyi on 31/08/2026.
//

#include "TStudent.h"

bool TStudent::operator>(const TStudent &other) const {
    return grade > other.grade;
}
