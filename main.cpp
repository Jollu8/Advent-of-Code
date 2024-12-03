//
// Created by Jollu Emil on 12/1/24.
//

#include "base/common.h"

#include <string>
#include <cassert>
#include <iostream>
#include <sstream>

const std::string PATH = "../";
const std::string Y_PATH = PATH + "2024/data/";

void test_f1_weak();

int main() {
    // 2024
    test_f1_weak();
}

void test_f1_weak() {

    Base *day_01 = new Day01{Y_PATH + "day-01.txt"};
    auto res_day_01 = dynamic_cast<Day01 *>(day_01)->day_01();
    assert(res_day_01.first == 1530215 && res_day_01.second == 26800609);
    std::cout << "TEST_2024_01 OK!\n";
/////////////////////
    Base *day_02 = new Day02{Y_PATH + "day-02.txt"};
    auto res_day_02 = dynamic_cast<Day02 *>(day_02)->day_02();
    assert(res_day_02.first == 483 && res_day_02.second == 528);
    std::cout << "TEST_2024_02 OK!\n";
////////////////////
    Base *day_03 = new Day03{Y_PATH + "day-03.txt"};
    auto res_day_03 = dynamic_cast<Day03 *>(day_03)->day_03();
    assert(res_day_03.first == 175615763 && res_day_03.second == 74361272);
    std::cout << "TEST_2024_03 OK!\n";

}