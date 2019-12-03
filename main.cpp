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
    std::string workflowFile = argv[1];
    Parser parser (workflowFile);
    Flow flow;
    parser.parse(flow);
    return 0;
}