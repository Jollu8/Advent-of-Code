//
// Created by Jollu Emil on 12/5/24.
//
#pragma once

#include "base.h"

class Day05 : public Base {
public:
    Day05(std::string fileName) : Base(std::move(fileName)) {}

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_05();

private:
    void parseFile();

    std::vector<std::pair<int, int>> m_rules;
    std::vector<std::vector<int>> m_updates;
};
