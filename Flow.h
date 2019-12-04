//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_FLOW_H
#define WORKFLOW_FLOW_H


#include <string>
#include <vector>
#include <unordered_map>

class Flow {
public:
    Flow() = default;
    std::vector <std::string> getFlowText() const {
        return text;
    }
    void setFlowText(std::vector<std::string> &_text);
    std::vector <std::string> getBlock(int id);
    bool checkId (int id);
    void setId (int id, std::vector<std::string> &block);
    void addToSequence (int id);
    void start();

private:
    std::unordered_map <int, std::vector <std::string>> idToBlock;
    std::vector <int> sequence;
    std::vector<std::string> text;
};


#endif //WORKFLOW_FLOW_H
