//
// Created by victor on 03.12.19.
//

#include "Dump.h"
#include <fstream>
#include <iostream>

Dump::Dump(std::string &_fileName) {
    fileName = _fileName;
}

void Dump::work(Flow &flow) {
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
    for (auto &i: text) {
        fout << i << "\n";
    }
    fout.close();
}
