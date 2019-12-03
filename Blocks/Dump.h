//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_DUMP_H
#define WORKFLOW_DUMP_H


#include "../Worker.h"

class Dump: public Worker {
public:
    explicit Dump(std::string &_fileName);
    void work(Flow &flow) override;

private:
    std::string fileName;
};


#endif //WORKFLOW_DUMP_H
