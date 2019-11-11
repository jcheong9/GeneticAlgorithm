//
// Created by jcheong on 2019-11-11.
//

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm(int city, int popsize) : CITIES_IN_TOUR{city}, POPULATION_SIZE{popsize}{
    startAlgo();
}

void GeneticAlgorithm::startAlgo() {
    createCities();
    double fitness = evaluateTourFitness();
    while(fitness < best_distance / base_distance < 1000){

    }
}

void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(City{});
    }
}
