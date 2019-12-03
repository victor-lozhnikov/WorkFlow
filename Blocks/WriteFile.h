//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_WRITEFILE_H
#define WORKFLOW_WRITEFILE_H


#include "../Worker.h"

class WriteFile: public Worker{
public:
    explicit WriteFile (std::string &_fileName);
    void work(Flow &flow) override;

private:
    std::string fileName;
};


#endif //WORKFLOW_WRITEFILE_H
