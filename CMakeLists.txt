cmake_minimum_required(VERSION 3.27)
project(kaylon_Riordan_CA3_Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(kaylon_Riordan_CA3_Cpp main.cpp
        Bug.cpp
        Bug.h
        Crawler.cpp
        Crawler.h
        Hopper.cpp
        Hopper.h
        Board.h
        Board.cpp
        Scuttler.cpp
        Scuttler.h
        SuperBug.cpp
        SuperBug.h
)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML/include)
target_link_libraries(kaylon_Riordan_CA3_Cpp sfml-system sfml-window sfml-graphics sfml-audio)

