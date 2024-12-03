//
// Created by Jollu Emil on 12/3/24.
//

#include "base.h"

#include <iostream>
#include <filesystem>


void Base::readFile() {
    if (!(std::filesystem::exists(m_fileName) && std::filesystem::is_regular_file(m_fileName))) {
        std::cerr << "ERROR: " << m_fileName << " is not readable!" << std::endl;
        return ;
    }
    std::ifstream input(m_fileName.c_str());
    if (!input.is_open()) {
        std::cerr << "ERROR: " << m_fileName << " could not be opened!" << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(input, line)) m_buff.emplace_back(line);

}