//
// Created by victor on 03.12.19.
//

#include "Grep.h"

Grep::Grep(std::string &_substr) {
    substr = _substr;
}

bool Grep::kmp(std::string &s) {
    std::string check = substr + (char)0 + s;
    int n = check.size();
    std::vector <int> pi (n);
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
        if (pi[i] == substr.size()) {
            return true;
        }
    }
    return false;
}

void Grep::work(Flow &flow) {
    std::vector <std::string> text = flow.getFlowText();
    std::vector <std::string> new_text;
    for (auto &i : text) {
        if (kmp(i)) {
            new_text.push_back(i);
        }
    }
    flow.setFlowText(new_text);
}
