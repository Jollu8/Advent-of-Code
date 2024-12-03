//
// Created by Jollu Emil on 12/2/24.
//
#include "2024/day-02.h"

#include <cmath>
#include <string>
#include <sstream>
#include <optional>

bool part_1_local(std::vector<int> &nums) {
    std::optional<bool> increasing{};
    for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
        int diff = *i - *(i - 1);
        if (diff == 0 || std::abs(diff) > 3) {
            return false;
        }
        bool inc = diff > 0;
        if (increasing.has_value()) {
            if (inc != increasing.value()) {
                return false;
            }
        } else {
            increasing = inc;
        }
    }
    return true;
}

bool part_2_local(std::vector<int> &nums) {
    if (part_1_local(nums)) {
        return true;
    }
    for (size_t i = 0; i < nums.size(); ++i) {
        auto cpy = std::vector{nums};
        cpy.erase(cpy.begin() + i);
        if (part_1_local(cpy)) return true;
    }
    return false;
}

std::pair<int, int> Day02::day_02() {
    size_t p1cnt{}, p2cnt{};
    for (const auto &line: m_buff) {
        if (line.empty()) continue;

        std::istringstream iss(line);
        std::vector<int> arr;
        std::string token;

        while (iss >> token) {
            if (!token.empty()) arr.emplace_back(std::stoi(token));
        }

        if (part_1_local(arr)) ++p1cnt;

        if (part_2_local(arr)) ++p2cnt;
    }
    return {p1cnt, p2cnt};
}


int Day02::part_1() {
    return {};
}

int Day02::part_2() {
    return {};
}