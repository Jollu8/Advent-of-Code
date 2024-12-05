//
// Created by Jollu Emil on 12/5/24.
//
#include "2024/day-04.h"

#include <iostream>
#include <vector>
#include <string>
#include <set>

class Point {
public:
    int x, y;

    Point(int x = 0, int y = 0) : x(x), y(y) {}

    Point operator+(const Point &other) const {
        return Point(x + other.x, y + other.y);
    }

    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }

    std::vector<Point> adjacent_points() const {
        return {
                Point(-1, -1), Point(0, -1), Point(1, -1),
                Point(-1, 0), Point(1, 0),
                Point(-1, 1), Point(0, 1), Point(1, 1)
        };
    }
};

std::string Day04::safe_get(const Point &loc) {
    if (loc.x < 0 || loc.x >= m_buff[0].size() || loc.y < 0 || loc.y >= m_buff.size()) {
        return "";
    }
    return std::string(1, m_buff[loc.y][loc.x]);
}

bool Day04::search(Point &loc, const Point &step) {
    for (char char_target: TARGET) {
        if (safe_get(loc) == std::string(1, char_target)) {
            loc = loc + step;
        } else {
            return false;
        }
    }
    return true;
}

bool Day04::is_xmas(const Point &loc) {
    std::vector<std::pair<Point, Point>> diags = {
            {Point(-1, -1), Point(1, 1)},
            {Point(-1, 1),  Point(1, -1)}
    };

    if (safe_get(loc) == "A") {
        for (const auto &diag: diags) {
            std::set<std::string> adjacent_chars;
            for (const auto &p: {diag.first, diag.second}) {
                adjacent_chars.insert(safe_get(loc + p));
            }
            if (adjacent_chars != std::set<std::string>{"M", "S"}) {
                return false;
            }
        }
        return true;
    }
    return false;
}

int Day04::part_1() {
    int cnt{};
    for (size_t y = 0; y < m_buff.size(); ++y) {
        for (size_t x = 0; x < m_buff[0].size(); ++x) {
            Point loc(x, y);
            for (const auto &adj: loc.adjacent_points()) {
                cnt += search(loc, adj) ? 1 : 0;
            }
        }
    }
    return cnt;
}

int Day04::part_2() {
    int cnt{};
    for (size_t y = 0; y < m_buff.size(); ++y) {
        for (size_t x = 0; x < m_buff[0].size(); ++x) {
            Point loc(x, y);
            cnt += is_xmas(loc) ? 1 : 0;
        }
    }
    return cnt;
}


std::pair<int, int> Day04::day_04() {
    auto res1 = part_1();
    auto res2 = part_2();
    return {res1, res2};
}


