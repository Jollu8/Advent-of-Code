//
// Created by Jollu Emil on 12/5/24.
//
#pragma once

#include "base.h"

class Point;

class Day04 : public Base {
public:
    Day04(std::string fileName) : Base(std::move(fileName)) {}

    int part_1() override;

    int part_2() override;

    std::pair<int, int> day_04();

private:

    std::string safe_get(const Point &loc);

    bool search(Point &loc, const Point &step);

    bool is_xmas(const Point &loc);

private:
    const std::string TARGET = "XMAS";
};
