cmake_minimum_required(VERSION 3.29)


set(unit_name  Advent_of_Code)
set(DIR_2024 "${CMAKE_SOURCE_DIR}/2024")
set(INCLUDE_2024 "${CMAKE_SOURCE_DIR}/2024/include/2024")
project(${unit_name})

set(CMAKE_CXX_STANDARD 23)


set(HDRS
        ${CMAKE_SOURCE_DIR}/templ/templates.h
        ${INCLUDE_2024}/day-01.h
)


set(SRC
        ${DIR_2024}/src/day-01.cpp
)

include_directories(${unit_name}
        ${CMAKE_SOURCE_DIR}/"2024"
        templ
        "${DIR_2024}/include"
)


add_executable(${unit_name}
        main.cpp
        ${HDRS}
        ${SRC}
)
