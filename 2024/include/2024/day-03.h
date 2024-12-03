//
// Created by Jollu Emil on 12/3/24.
//
#pragma once

#include "base.h"
#include <string>

class Day03 : public Base {
public:
    Day03(std::string fileName) : Base(std::move(fileName)) {}

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_03();
};
