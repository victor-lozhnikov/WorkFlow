//
// Created by victor on 03.12.19.
//

#include <iostream>
#include "Replace.h"

Replace::Replace(std::string &_from, std::string &_to) {
    from = _from;
    to = _to;
}

std::vector <int> Replace::findSubstrPos (std::string &s) {
    std::string check = from + (char)0 + s;
    int n = check.size();
    std::vector <int> pi (n);
    std::vector <int> pos;
    pi[0] = 0;
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && check[i] != check[j]) {
            j = pi[j - 1];
        }
        if (check[i] == check[j]) {
            j++;
        }
        pi[i] = j;
        if (pi[i] == from.size()) {
            pos.push_back(i - from.size() - 1);
            pi[i] = 0;
        }
    }
    return pos;
}

void Replace::work(Flow &flow) {
    std::vector <std::string> text = flow.getFlowText();
    std::vector <std::string> new_text;
    for (auto &i : text) {
        std::vector<int> pos = findSubstrPos(i);
        if (pos.empty()) {
            new_text.push_back(i);
            continue;
        }
        std::vector<std::string> splits;
        splits.push_back(i.substr(0, pos[0] - from.size() + 1));
        for (int j = 1; j < pos.size(); ++j) {
            splits.push_back(i.substr(pos[j - 1] + 1,
                    pos[j] - pos[j - 1] - from.size()));
        }
        if (pos.back() != i.size() - 1) {
            splits.push_back(i.substr(pos.back() + 1,
                    i.size() - pos.back() - 1));
        }
        else {
            splits.emplace_back("");
        }
        std::string new_str;
        for (int j = 0; j < splits.size(); ++j) {
            new_str += splits[j];
            if (j != splits.size() - 1) {
                new_str += to;
            }
        }
        new_text.push_back(new_str);
    }
    flow.setFlowText(new_text);
    std::cout << flow.getFlowText()[0];
}