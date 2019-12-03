//
// Created by victor on 03.12.19.
//

#include "ReadFile.h"
#include <fstream>

ReadFile::ReadFile(std::string &_fileName) {
    fileName = _fileName;
}

void ReadFile::work(Flow &flow) {
    std::ifstream fin (fileName);
    std::vector <std::string> _text;
    std::string s;
    while (fin) {
        getline(fin, s);
        _text.push_back(s);
    }
    flow.setFlowText(_text);
}