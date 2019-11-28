//
// Created by jcheong on 2019-11-25.

//#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Tour.hpp"
#include "Population.hpp"
#include "City.hpp"
#include "GeneticAlgorithm.hpp"
#include "UI.hpp"
/*
TEST_CASE("Test", "test") {
    REQUIRE(1 == 1);
}
//test findEliteSelection function
TEST_CASE("Test findEliteSelection", "population") {
    City a{};
    City b{};
    City c{};
    City d{};
    City e{};
    vector<City *> masterCities{&a, &b, &c, &d, &e};
    Tour tour1{masterCities};
    Population population;

    vector<City *> tmpList = masterCities;
    auto rn = default_random_engine{};

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 64; j++) {
            shuffle(tmpList.begin(), tmpList.end(), rn);
        }
        population.addListTour(Tour{tmpList});
    }
    Tour beforeTour = population.getListTour().at(0);
    double tBefore = beforeTour.get_tour_distance();
    population.findEliteSelection();
    Tour afterTour = population.getListTour().at(0);
    double tAfter = afterTour.get_tour_distance();
    REQUIRE(tBefore != tAfter);
}


//test mergeToursCurrentPopulation function correctly and same size as original
TEST_CASE("Test mergeToursCurrentPopulation", "population") {
    City a {};
    City b {};
    City c {};
    City d {};
    City e {};
    vector<City*> masterCities{&a, &b, &c, &d, &e};
    Tour tour1{masterCities};
    Population population;

    vector<City*> tmpList = masterCities;
    auto rn = default_random_engine{};

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 64; j ++){
            shuffle(tmpList.begin(),tmpList.end(),rn);
        }
        population.addListTour(Tour{tmpList});
    }
    population.findEliteSelection();
    vector<Tour> listTour = population.getListTour();
    population.mergeToursCurrentPopulation();
    vector<Tour> listTourMerge = population.getListTour();
    REQUIRE(listTour.size() == listTourMerge.size());
}

*/
