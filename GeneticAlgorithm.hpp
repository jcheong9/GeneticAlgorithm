//
// Created by jcheong on 2019-11-11.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include <vector>
#include "City.hpp"

class GeneticAlgorithm {
const int IMPROVEMENT_FACTOR  = 25;

private:
    int CITIES_IN_TOUR;
    int POPULATION_SIZE;
    vector<City*> masterCities;
public:
    GeneticAlgorithm() = default;
    GeneticAlgorithm(int city, int popsize);
    ~GeneticAlgorithm() = default;

    void startAlgo();

    void createCities();
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
