//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_WORKER_H
#define WORKFLOW_WORKER_H

#include <string>
#include "Flow.h"

class Worker {
private:
    virtual void work(Flow &flow) = 0;
};


#endif //WORKFLOW_WORKER_H
