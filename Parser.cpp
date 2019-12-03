//
// Created by victor on 03.12.19.
//

#include "Parser.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>

Parser::Parser(std::string &_fileName) {
    fileName = _fileName;
}

std::vector<std::string> Parser::split (const std::string &s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss (s);
    std::string item;
    while (getline (ss, item, delim)) {
        result.push_back (item);
    }
    return result;
}

void Parser::wrongIdException(std::string &id, int it) {
    std::cerr << "EXCEPTION: wrong ID format \"" << id << "\" (line " << it << ")\n";
    exit(1);
}

int Parser::stringToInt(std::string &s, int it) {
    if (s.size() > 9 || (s.size() > 1 && s[0] == '0')) {
        wrongIdException(s, it);
    }
    int id = 0, p10 = 1;
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] < '0' || s[i] > '9') {
            wrongIdException(s, it);
        }
        id += p10 * (s[i] - '0');
        p10 *= 10;
    }
    return id;
}

void Parser::parse(Flow &flow) {
    std::ifstream fin (fileName);
    std::string tmp;
    getline(fin, tmp);
    std::vector <std::string> splited = split(tmp, ' ');
    if (splited.size() > 1) {
        std::cerr << "EXCEPTION: invalid input format (line " <<
                  1 << ")\n";
        exit(1);
    }
    if (splited[0] != "desc") {
        std::cerr << "EXCEPTION: string \"desc\" is not found\n";
        exit(1);
    }

    std::unordered_map <std::string, int> commands;
    commands["readfile"] = 1;
    commands["writefile"] = 1;
    commands["grep"] = 1;
    commands["sort"] = 0;
    commands["replace"] = 2;
    commands["dump"] = 1;

    int it = 2;
    while (fin) {
        getline(fin, tmp);
        splited = split(tmp, ' ');
        if (splited.size() == 1) {
            if (splited[0] == "csed") {
                break;
            }
            else {
                std::cerr << "EXCEPTION: string \"csed\" is not found\n";
                exit(1);
            }
        }
        if (splited.size() < 3) {
            std::cerr << "EXCEPTION: invalid input format (line " <<
                    it << ")\n";
            exit(1);
        }
        int id = stringToInt(splited[0], it);
        //std::cout << id << "\n";
        if (splited[1] != "=") {
            std::cerr << "EXCEPTION: not found \"=\" in line " << it << "\n";
            exit(1);
        }

        if (commands.count(splited[2]) == 0) {
            std::cerr << "EXCEPTION: command \"" << splited[2] <<
                    "\" is not found (line " << it << ")\n";
            exit(1);
        }

        if (commands[splited[2]] != splited.size() - 3) {
            std::cerr << "EXCEPTION: invalid number of arguments for command \"" <<
                    splited[2] << "\", expected " << commands[splited[2]] <<
                    ", have " << splited.size() - 3 << " (line " << it << ")\n";
            exit(1);
        }
        it++;
    }
    getline(fin, tmp);
    splited = split(tmp, ' ');
    if (splited.size() % 2 == 0) {
        std::cerr << "EXCEPTION: invalid input format (line " <<
                  it << ")\n";
        exit(1);
    }

    for (int i = 0; i < splited.size(); i += 2) {

    }
}
