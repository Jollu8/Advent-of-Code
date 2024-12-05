//
// Created by Jollu Emil on 12/3/24.
//

#include "2024/day-03.h"

#include <string>
#include <regex>

int Day03::part_1() {
    int cnt{};
    std::regex mulRegex(R"(mul\((\d+),(\d+)\))");
    auto buff = m_buff;
    for (auto &line: buff) {
        std::smatch match;

        while (std::regex_search(line, match, mulRegex)) {
            cnt += std::stoi(match[1]) * std::stoi(match[2]);
            line = match.suffix().str();
        }
    }
    return cnt;
}

int Day03::part_2() {
    int cnt{};
    bool action = true;
    std::regex actionRegex(R"((mul)\((\d+),(\d+)\)|(do)\(\)|(don't)\(\))");
    for (auto &line: m_buff) {
        std::smatch match;

        while (std::regex_search(line, match, actionRegex)) {

            if (match[1] == "mul" && action) cnt += std::stoi(match[2]) * std::stoi(match[3]);

            if (match.str() == "do()") action = true;

            if (match.str() == "don't()") action = false;

            line = match.suffix().str();
        }
    }
    return cnt;
}

std::pair<int, int> Day03::day_03() {
    int p1cnt = part_1();
    int p2cnt = part_2();
    return {p1cnt, p2cnt};
}



