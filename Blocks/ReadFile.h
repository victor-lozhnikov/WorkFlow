//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_READFILE_H
#define WORKFLOW_READFILE_H


#include "../Worker.h"

class ReadFile: public Worker {
public:
    explicit ReadFile (std::string &_fileName);
    void work(Flow &flow) override;

private:
    std::string fileName;
};


#endif //WORKFLOW_READFILE_H
