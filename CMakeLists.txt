cmake_minimum_required(VERSION 3.10.0)

project(CellularAutomata VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SRC_FILES
    "${CMAKE_SOURCE_DIR}/source/cpp/*.cpp"
)

add_executable(CellularAutomata
    source/main.cpp
    ${SRC_FILES}
)

target_include_directories(CellularAutomata PRIVATE
    ${CMAKE_SOURCE_DIR}/external/SDL2/include
    ${CMAKE_SOURCE_DIR}/source/h
)

target_link_directories(CellularAutomata PRIVATE
    ${CMAKE_SOURCE_DIR}/external/SDL2/lib
)

target_link_libraries(CellularAutomata
    mingw32
    SDL2main
    SDL2
)