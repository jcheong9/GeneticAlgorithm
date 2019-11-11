//
// Created by jcheong on 2019-11-11.
//

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm(int city, int popsize) : CITIES_IN_TOUR{city}, POPULATION_SIZE{popsize}{
    startAlgo();
}

void GeneticAlgorithm::startAlgo() {
    createCities();

    double base_distance = evaluateTourFitness();
    int iterations = 0;
    double improvment = best_distance / base_distance;
    while(fitness < improvement || iterations < ITERATIONS){

    }
}

void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(new City());
    }
}

GeneticAlgorithm::~GeneticAlgorithm() {
    while(!masterCities.empty()){
        delete masterCities.back();
        masterCities.pop_back();
    }
}

double GeneticAlgorithm::evaluateTourFitness() {

    return 0;
}
