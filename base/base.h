//
// Created by Jollu Emil on 12/1/24.
//
#pragma once

#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <charconv>

class Base {
public:
    Base() = delete;

    explicit Base(std::string &&fileName) :
            m_fileName(fileName) {
        readFile();
    }

    virtual  ~Base() = default;

    void readFile();

    virtual int part_1() = 0;

    virtual int part_2() = 0;

protected:
    std::filesystem::path m_fileName;
    std::vector<std::string> m_buff;
};
