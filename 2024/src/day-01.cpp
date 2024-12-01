//
// Created by Jollu Emil on 12/1/24.
//

#include "templates.h"
#include "2024/day-01.h"

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>


std::pair<int, int> Day01::day_01() {
    if (!readFile()) return {};
    int res1 = part_1();
    int res2 = part_2();
    return {res1, res2};
}

int Day01::part_1() {
    auto aBegin = a.begin();
    auto cBegin = c.begin();
    int ans{};
    for (; aBegin != a.end(); ++aBegin, ++cBegin)
        ans += std::abs(*aBegin - *cBegin);

    return ans;
}

int Day01::part_2() {
    return std::accumulate(a.begin(), a.end(), 0, [&](auto sum, auto num) {
        if (c.contains(num)) return sum + num * mp[num];
        return sum;
    });
}

bool Day01::readFile() {

    if (!m_fileName.is_open()) {
        std::cerr << "Cannot open file " << m_fileName.rdbuf() << std::endl;
        return false;
    }
    std::string line;
    try {
        while (std::getline(m_fileName, line)) {
            std::istringstream iss(line);
            int x, y;
            if (iss >> x >> y) {
                a.insert(x);
                c.insert(y);
                mp[y]++;
            }
        }
    } catch (const std::exception &e) {
        std::cerr << "Exception while reading from file " << m_fileName.rdbuf() << ": " << e.what() << std::endl;
        return false;
    }

    return true;
}
