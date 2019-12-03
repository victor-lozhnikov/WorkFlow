//
// Created by victor on 03.12.19.
//

#include "WriteFile.h"
#include <fstream>

WriteFile::WriteFile(std::string &_fileName) {
    fileName = _fileName;
}

void WriteFile::work(Flow &flow) {
    std::ofstream fout (fileName);
    std::vector <std::string> text = flow.getFlowText();
    for (auto &i : text) {
        fout << i << "\n";
    }
}