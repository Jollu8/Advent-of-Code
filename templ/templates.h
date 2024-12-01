//
// Created by Jollu Emil on 12/1/24.
//
#pragma once

#include <fstream>

class Templ {
public:
    Templ() = delete;

    explicit Templ(std::string&& fileName) :
            m_fileName(fileName) {}

    ~Templ();

    virtual bool readFile() = 0;

    virtual int part_1() = 0;

    virtual int part_2() = 0;

protected:
    std::ifstream m_fileName;
};