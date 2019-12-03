//
// Created by victor on 03.12.19.
//

#include "Sort.h"
#include <algorithm>

void Sort::work(Flow &flow) {
    std::vector <std::string> text = flow.getFlowText();
    std::sort(text.begin(), text.end());
    flow.setFlowText(text);
}