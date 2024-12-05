//
// Created by Jollu Emil on 12/5/24.
//

#include "2024/day-05.h"

#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>


using vp = std::vector<std::pair<int, int>>;
using v = std::vector<int>;

bool isUpdateInRightOrder(const v &update, const vp &rules);

int getMiddlePage(const v &update);

int comparePages(int x, int y, const vp &rules);

std::pair<int, int> Day05::day_05() {
    parseFile();
    int res1 = part_1();
    int res2 = part_2();
    return {res1, res2};
}

int Day05::part_1() {
    v middle_pages;
    for (const auto &update: m_updates) {
        if (isUpdateInRightOrder(update, m_rules)) middle_pages.push_back(getMiddlePage(update));
    }
    return accumulate(middle_pages.begin(), middle_pages.end(), 0);
}


v correctUpdate(const v &update, const vp &rules) {
    v sorted_update = update;
    sort(sorted_update.begin(), sorted_update.end(), [&](int x, int y) {
        return comparePages(x, y, rules) > 0;
    });
    return sorted_update;
}

int Day05::part_2() {
    v middle_pages;
    for (const auto &update: m_updates) {
        if (!isUpdateInRightOrder(update, m_rules)) {
            auto corrected_update = correctUpdate(update, m_rules);
            middle_pages.push_back(getMiddlePage(corrected_update));
        }
    }
    return accumulate(middle_pages.begin(), middle_pages.end(), 0);
}

bool isUpdateInRightOrder(const v &update, const vp &rules) {
    for (const auto &rule: rules) {
        int x = rule.first;
        int y = rule.second;
        auto it_x = find(update.begin(), update.end(), x);
        auto it_y = find(update.begin(), update.end(), y);
        if (it_x != update.end() && it_y != update.end()) {
            if (it_x > it_y) return false;
        }
    }
    return true;
}

int getMiddlePage(const v &update) {
    return update[(update.size() - 1) / 2];
}

int comparePages(int x, int y, const vp &rules) {
    if (isUpdateInRightOrder({x, y}, rules)) {
        return 1;
    }
    return -1;
}

void Day05::parseFile() {


    for (auto &line: m_buff) {
        line.erase(remove(line.begin(), line.end(), '\n'), line.end());
        line.erase(remove(line.begin(), line.end(), '\r'), line.end());
        line.erase(remove_if(line.begin(), line.end(), [](unsigned char c) { return isspace(c); }), line.end());

        if (line.find('|') != std::string::npos) {
            int x, y;
            sscanf(line.c_str(), "%d|%d", &x, &y);
            m_rules.emplace_back(x, y);
        } else if (line.find(',') != std::string::npos) {
            v pages;
            std::stringstream ss(line);
            std::string token;
            while (getline(ss, token, ',')) {
                pages.push_back(stoi(token));
            }
            m_updates.push_back(pages);
        }
    }
}