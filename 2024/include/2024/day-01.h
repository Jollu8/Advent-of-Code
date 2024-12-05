//
// Created by Jollu Emil on 12/1/24.
//
#pragma once

#include "base.h"

class Day01 : public Base {
public:
    Day01(std::string fileName) : Base(std::move(fileName)) {}

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_01();

};
