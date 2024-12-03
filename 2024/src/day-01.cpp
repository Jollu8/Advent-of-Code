//
// Created by Jollu Emil on 12/1/24.
//

#include "2024/day-01.h"

#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>

std::map<int, int> mp;
std::multiset<int> a, c;

std::pair<int, int> Day01::day_01() {
    for (auto &str: m_buff) {
        std::stringstream ss(str);
        int x, y;
        ss >> x >> y;
        a.insert(x);
        c.insert(y);
        mp[y]++;
    }

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

