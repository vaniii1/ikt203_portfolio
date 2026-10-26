//
// Created by Ivan Hromovyi on 26/10/2026.
//

#ifndef IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTVIEW_H
#define IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTVIEW_H


#include "../controlller/TextController.h"

class TextView {
private:
    TextController *textController;
  public:
    TextView();
    ~TextView();

    void generateMenu();
};


#endif //IKT203_ALGORITHMS_DATASTRUCTURE_DOCUMENTVIEW_H