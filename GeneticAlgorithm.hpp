//
// Created by jcheong on 2019-11-11.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include <vector>
#include "City.hpp"
#include "Population.hpp"

class GeneticAlgorithm {
const double IMPROVEMENT_FACTOR = 0.75;
const int ITERATIONS = 1000;
const int SHUFFLES = 64;
private:
    int CITIES_IN_TOUR;
    int POPULATION_SIZE;
    vector<City *> masterCities;
    Population population;
public:
    //constructors
    GeneticAlgorithm() = default;
    GeneticAlgorithm(int city, int popsize);
    //function prototype
    void startAlgo();
    void createCities();
    void printFinalReport(bool achieved, int iterations, double distance, double distance1,
            double improvement, Tour tour);
    void printIteration(double improvement,double best_distance,int iterations);
    void createPopulation();
    //destructor
    ~GeneticAlgorithm();
};


#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
