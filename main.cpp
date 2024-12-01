//
// Created by Jollu Emil on 12/1/24.
//

#include "2024/day-01.h"

#include <fstream>
#include <string>
#include <cassert>
#include <iostream>

const std::string PATH = "../";
const std::string Y_PATH = PATH + "2024/data/";


int main() {
    // 2024
    {
        Templ *day_01 = new Day01{Y_PATH + "day-01.txt"};
        auto res_day_01 = dynamic_cast<Day01 *>(day_01)->day_01();
        assert(res_day_01.first == 1530215 && res_day_01.second == 26800609);
        std::cout << "TEST_2024 OK!\n";
    }
}