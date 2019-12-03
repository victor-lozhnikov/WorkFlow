//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_SORT_H
#define WORKFLOW_SORT_H


#include "../Worker.h"

class Sort: public Worker {
public:
    Sort() = default;
    void work(Flow &flow) override;
};


#endif //WORKFLOW_SORT_H
