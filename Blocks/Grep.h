//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_GREP_H
#define WORKFLOW_GREP_H


#include "../Worker.h"

class Grep: public Worker {
public:
    explicit Grep(std::string &_substr);
    void work(Flow &flow) override;
    bool kmp(std::string &s);

private:
    std::string substr;
};


#endif //WORKFLOW_GREP_H
