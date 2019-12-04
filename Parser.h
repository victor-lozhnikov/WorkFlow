//
// Created by victor on 03.12.19.
//

#ifndef WORKFLOW_PARSER_H
#define WORKFLOW_PARSER_H


#include <string>
#include <fstream>
#include "Flow.h"

class Parser {
public:
    explicit Parser(std::string &_fileName);
    void parse(Flow &flow);

private:
    std::string fileName;
    int stringToInt(std::string &s, int it);
    void wrongIdException(std::string &id, int it);
    std::vector<std::string> split(const std::string &s, char delim);
    std::ifstream fin;
};

#endif //WORKFLOW_PARSER_H
