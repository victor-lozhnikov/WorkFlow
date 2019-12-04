//
// Created by victor on 03.12.19.
//

#include "ReadFile.h"
#include <fstream>
#include <iostream>

ReadFile::ReadFile(std::string &_fileName) {
    fileName = _fileName;
}

void ReadFile::work(Flow &flow) {
    std::ifstream fin;
    fin.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try {
        fin.open(fileName);
    }
    catch (std::ifstream::failure &e) {
        std::cerr << "EXCEPTION: can't open file \"" << fileName << "\"\n";
        exit(1);
    }
    std::vector <std::string> _text;
    std::string s;
    while (fin) {
        try {
            getline(fin, s);
            _text.push_back(s);
        }
        catch (std::ifstream::failure &e) {
            break;
        }
    }
    flow.setFlowText(_text);
    fin.close();
}