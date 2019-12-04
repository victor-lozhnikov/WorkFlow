//
// Created by victor on 03.12.19.
//

#include "WriteFile.h"
#include <fstream>
#include <iostream>

WriteFile::WriteFile(std::string &_fileName) {
    fileName = _fileName;
}

void WriteFile::work(Flow &flow) {
    std::ofstream fout;
    fout.exceptions ( std::ofstream::failbit | std::ofstream::badbit );
    try {
        fout.open(fileName);
    }
    catch (std::ofstream::failure &e) {
        std::cerr << "EXCEPTION: can't open file \"" << fileName << "\"\n";
        exit(1);
    }
    std::vector <std::string> text = flow.getFlowText();
    for (auto &i : text) {
        fout << i << "\n";
    }
    fout.close();
}