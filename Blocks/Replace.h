//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_REPLACE_H
#define WORKFLOW_REPLACE_H


#include "../Worker.h"

class Replace: public Worker {
public:
    Replace(std::string &_from, std::string &_to);
    void work(Flow &flow) override;

private:
    std::string from;
    std::string to;
};


#endif //WORKFLOW_REPLACE_H
