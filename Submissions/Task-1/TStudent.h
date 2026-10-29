//
// Created by Ivan Hromovyi on 31/08/2026.
//

#ifndef TEMPLATES_CALLBACKS_TSTUDENT_H
#define TEMPLATES_CALLBACKS_TSTUDENT_H


struct TStudent {
    int grade;

    bool operator>(const TStudent& other) const;
};


#endif //TEMPLATES_CALLBACKS_TSTUDENT_H