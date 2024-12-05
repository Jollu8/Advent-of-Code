//
// Created by Jollu Emil on 12/2/24.
//
#pragma once
#include "base.h"

class Day02 : public Base {
public:
    Day02(std::string fileName): Base(std::move(fileName)) {}

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_02();
};