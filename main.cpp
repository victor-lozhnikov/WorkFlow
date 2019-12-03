#include <iostream>
#include <string>
#include "Worker.h"
#include "Blocks/ReadFile.h"
#include "Blocks/WriteFile.h"
#include "Blocks/Grep.h"
#include "Blocks/Sort.h"
#include "Blocks/Dump.h"

int main() {
    std::string input = "input.txt";
    std::string output = "output.txt";
    std::string find = "k";
    std::string dumpFile = "dump.txt";
    Flow flow;
    ReadFile readFile(input);
    readFile.work(flow);
    Grep grep (find);
    grep.work(flow);
    Dump dump (dumpFile);
    dump.work(flow);
    Sort sort;
    sort.work(flow);
    WriteFile writeFile(output);
    writeFile.work(flow);
    return 0;
}