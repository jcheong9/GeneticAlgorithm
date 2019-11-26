//
// Created by jcheong on 2019-11-25.
//
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Tour.hpp"
#include "Population.hpp"
#include "City.hpp"
#include "GeneticAlgorithm.hpp"
#include "UI.hpp"

//push and pop function
TEST_CASE("A new stack is empty", "stack") {
    myStack tester;
    tester.push(2);
    tester.pop();
    REQUIRE(tester.empty() == true); REQUIRE(tester.full() == false);
}

