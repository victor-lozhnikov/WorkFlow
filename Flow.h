//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_FLOW_H
#define WORKFLOW_FLOW_H


#include <string>
#include <vector>

class Flow {
public:
    std::vector <std::string> getFlowText() const {
        return text;
    }
    void setFlowText(std::vector<std::string> &_text);
private:
    std::vector<std::string> text;
};


#endif //WORKFLOW_FLOW_H
