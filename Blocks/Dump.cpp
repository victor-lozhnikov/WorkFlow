//
// Created by victor on 03.12.19.
//

#include "Dump.h"
#include <fstream>

Dump::Dump(std::string &_fileName) {
    fileName = _fileName;
}

void Dump::work(Flow &flow) {
    std::ofstream fout(fileName);
    std::vector <std::string> text = flow.getFlowText();
    for (auto &i: text) {
        fout << i << "\n";
    }
}
