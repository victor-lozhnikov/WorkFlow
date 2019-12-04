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
    std::cerr << "EXCEPTION: invalid ID format \"" << id << "\" (line " << it << ")\n";
    fin.close();
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
    fin.exceptions ( std::ifstream::failbit | std::ifstream::badbit );
    try {
        fin.open(fileName);
    }
    catch (std::ifstream::failure &e) {
        std::cerr << "EXCEPTION: can't open file \"" << fileName << "\"\n";
        fin.close();
        exit(1);
    }
    std::string tmp;
    try {
        getline(fin, tmp);
    }
    catch (std::ifstream::failure &e) {
        std::cerr << "EXCEPTION: unexpected end of file \"" << fileName << "\"\n";
        fin.close();
        exit(1);
    }
    std::vector <std::string> splited = split(tmp, ' ');
    if (splited.size() > 1) {
        std::cerr << "EXCEPTION: invalid input format (line " <<
                  1 << ")\n";
        fin.close();
        exit(1);
    }
    if (splited[0] != "desc") {
        std::cerr << "EXCEPTION: string \"desc\" is not found\n";
        fin.close();
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
    while (true) {
        try {
            getline(fin, tmp);
        }
        catch (std::ifstream::failure &e) {
            std::cerr << "EXCEPTION: unexpected end of file \"" << fileName << "\"\n";
            fin.close();
            exit(1);
        }
        splited = split(tmp, ' ');
        if (splited.size() == 1) {
            if (splited[0] == "csed") {
                break;
            }
            else {
                std::cerr << "EXCEPTION: string \"csed\" is not found\n";
                fin.close();
                exit(1);
            }
        }
        if (splited.size() < 3) {
            std::cerr << "EXCEPTION: invalid input format (line " <<
                    it << ")\n";
            fin.close();
            exit(1);
        }
        int id = stringToInt(splited[0], it);
        if (flow.checkId(id)) {
            std::cerr << "EXCEPTION: ID \"" << id << "\" was reused (line " <<
            it << ")\n";
            fin.close();
            exit(1);
        }
        //std::cout << id << "\n";
        if (splited[1] != "=") {
            std::cerr << "EXCEPTION: \"=\" is not found (line " << it << ")\n";
            fin.close();
            exit(1);
        }

        if (commands.count(splited[2]) == 0) {
            std::cerr << "EXCEPTION: command \"" << splited[2] <<
                    "\" is not found (line " << it << ")\n";
            fin.close();
            exit(1);
        }

        if (commands[splited[2]] != splited.size() - 3) {
            std::cerr << "EXCEPTION: invalid number of arguments for command \"" <<
                    splited[2] << "\", expected " << commands[splited[2]] <<
                    ", have " << splited.size() - 3 << " (line " << it << ")\n";
            fin.close();
            exit(1);
        }
        splited.erase(splited.begin(), splited.begin() + 2);
        flow.setId(id, splited);
        it++;
    }
    try {
        getline(fin, tmp);
    }
    catch (std::ifstream::failure &e) {
        std::cerr << "EXCEPTION: unexpected end of file \"" << fileName << "\"\n";
        fin.close();
        exit(1);
    }
    splited = split(tmp, ' ');
    if (splited.size() % 2 == 0) {
        std::cerr << "EXCEPTION: invalid input format (line " <<
                  it << ")\n";
        fin.close();
        exit(1);
    }

    for (int i = 0; i < splited.size(); i += 2) {
        int id = stringToInt(splited[i], it);
        if (!flow.checkId(id)) {
            std::cerr << "EXCEPTION: ID \"" << id << "\" is not found (line " <<
                    it << ")\n";
            fin.close();
            exit(1);
        }
        flow.addToSequence(id);
        if (i != splited.size() - 1 && splited[i + 1] != "->") {
            std::cerr << "EXCEPTION: \"->\" is not found (line " << it << ")\n";
            fin.close();
            exit(1);
        }
    }
    fin.close();
}
