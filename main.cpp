#include <iostream>
#include <string>
#include "Worker.h"
#include "Blocks/ReadFile.h"
#include "Blocks/WriteFile.h"
#include "Blocks/Grep.h"
#include "Blocks/Sort.h"
#include "Blocks/Dump.h"
#include "Parser.h"
#include "Blocks/Replace.h"

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cerr << "EXCEPTION: expected 1 program argument with file name\n";
        exit(1);
    }
    std::string workflowFile = argv[1];
    Parser parser (workflowFile);
    Flow flow;
    parser.parse(flow);
    flow.start();
    return 0;
}