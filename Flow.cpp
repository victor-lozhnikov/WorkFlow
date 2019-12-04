//
// Created by victor on 03.12.19.
//

#include "Flow.h"
#include "Blocks/ReadFile.h"
#include "Blocks/WriteFile.h"
#include "Blocks/Grep.h"
#include "Blocks/Sort.h"
#include "Blocks/Replace.h"
#include "Blocks/Dump.h"
#include <iostream>

void Flow::setFlowText(std::vector<std::string> &_text) {
    text = _text;
}

std::vector <std::string> Flow::getBlock(int id) {
    return idToBlock[id];
}

bool Flow::checkId(int id) {
    return idToBlock.count(id);
}

void Flow::setId(int id, std::vector<std::string> &block) {
    idToBlock[id] = block;
}

void Flow::addToSequence(int id) {
    sequence.push_back(id);
}

void Flow::start() {
    for (int i = 0; i < sequence.size(); ++i) {
        if (i == 0 && idToBlock[sequence[i]][0] != "readfile") {
            std::cerr << "EXCEPTION: the first command in the flow must be \"readfile\"\n";
            exit(1);
        }
        if (i == sequence.size() - 1 && idToBlock[sequence[i]][0] != "writefile") {
            std::cerr << "EXCEPTION: the last command in the flow must be \"writefile\"\n";
            exit(1);
        }
        if (idToBlock[sequence[i]][0] == "readfile" && i != 0) {
            std::cerr << "EXCEPTION: command \"readfile\" can only be at the beginning of the flow\n";
            exit(1);
        }
        if (idToBlock[sequence[i]][0] == "writefile" && i != sequence.size() - 1) {
            std::cerr << "EXCEPTION: command \"writefile\" can only be at the end of the flow\n";
            exit(1);
        }

        if (idToBlock[sequence[i]][0] == "readfile") {
            ReadFile readFile(idToBlock[sequence[i]][1]);
            readFile.work(*this);
        }
        if (idToBlock[sequence[i]][0] == "writefile") {
            WriteFile writeFile(idToBlock[sequence[i]][1]);
            writeFile.work(*this);
        }
        if (idToBlock[sequence[i]][0] == "grep") {
            Grep grep(idToBlock[sequence[i]][1]);
            grep.work(*this);
        }
        if (idToBlock[sequence[i]][0] == "sort") {
            Sort sort;
            sort.work(*this);
        }
        if (idToBlock[sequence[i]][0] == "replace") {
            Replace replace(idToBlock[sequence[i]][1], idToBlock[sequence[i]][2]);
            replace.work(*this);
        }
        if (idToBlock[sequence[i]][0] == "dump") {
            Dump dump(idToBlock[sequence[i]][1]);
            dump.work(*this);
        }
    }
}