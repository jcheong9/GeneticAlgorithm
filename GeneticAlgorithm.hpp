//
// Created by jcheong on 2019-11-11.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include <vector>
#include "City.hpp"

class GeneticAlgorithm {
const int IMPROVEMENT_FACTOR  = 25;
const int ITERATIONS = 1000;
private:
    int CITIES_IN_TOUR;
    int POPULATION_SIZE;
    vector<City*> masterCities;
public:
    GeneticAlgorithm() = default;
    GeneticAlgorithm(int city, int popsize);

    void startAlgo();

    void createCities();
    ~GeneticAlgorithm();
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
