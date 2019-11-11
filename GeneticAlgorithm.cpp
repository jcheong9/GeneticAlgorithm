//
// Created by jcheong on 2019-11-11.
//

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm(int city, int popsize) : CITIES_IN_TOUR{city}, POPULATION_SIZE{popsize}{
    startAlgo();
}

void GeneticAlgorithm::startAlgo() {
    createCities();
    createPopulation();
    double base_distance = evaluateTourFitness();
    int iterations = 0;
    double improvement = best_distance / base_distance;
    while(improvement < IMPROVEMENT_FACTOR || iterations < ITERATIONS){

    }
}

void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(new City());
    }
}

double GeneticAlgorithm::evaluateTourFitness() {
    
    return 0;
}

//create the population and shuffle each tour of SHUFFLES
void GeneticAlgorithm::createPopulation() {
    for(int i = 0; i < POPULATION_SIZE; i++){
        population.getListTour().push_back((new Tour(masterCities)));
        for(int j = 0; j < SHUFFLES; j ++){
            population.getListTour().at(i)->shuffle_cities();
        }
    }
}

//destructor delete the allocated memories
GeneticAlgorithm::~GeneticAlgorithm() {
    while(!masterCities.empty()){
        delete masterCities.back();
        masterCities.pop_back();
    }
}