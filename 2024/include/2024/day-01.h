//
// Created by Jollu Emil on 12/1/24.
//
#include "templates.h"

#include <fstream>
#include <string>
#include <map>
#include <set>


#pragma once

class Day01 : public Templ {
public:
    Day01(std::string fileName): Templ(std::move(fileName)) {}
    bool readFile() override;

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_01();

private:
    std::map<int, int> mp;
    std::multiset<int> a, c;
};
