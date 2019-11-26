cmake_minimum_required(VERSION 3.14)
project(GeneticAlgorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(GeneticAlgorithm main.cpp City.cpp City.hpp Tour.hpp Tour.cpp Population.cpp Population.hpp UI.cpp UI.hpp GeneticAlgorithm.cpp GeneticAlgorithm.hpp unit_test.cpp)