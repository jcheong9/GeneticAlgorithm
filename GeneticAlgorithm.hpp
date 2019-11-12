//
// Created by jcheong on 2019-11-11.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include <vector>
#include "City.hpp"
#include "Population.hpp"

class GeneticAlgorithm {
const double IMPROVEMENT_FACTOR  = 0.25;
const int ITERATIONS = 1000;
const int SHUFFLES = 64;
private:
    int CITIES_IN_TOUR;
    int POPULATION_SIZE;
    vector<City*> masterCities;
    Population population;
public:
    GeneticAlgorithm() = default;
    GeneticAlgorithm(int city, int popsize);

    void startAlgo();

    void createCities();
    ~GeneticAlgorithm();

    double evaluateTourFitness();

    void createPopulation();
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
