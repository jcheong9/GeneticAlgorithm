//
// Created by jcheong on 2019-11-11.
//

#include <iostream>
#include "GeneticAlgorithm.hpp"
//constructor
GeneticAlgorithm::GeneticAlgorithm(int city, int popsize) : CITIES_IN_TOUR{city}, POPULATION_SIZE{popsize}{
    startAlgo();
}
//starts the algorithm
void GeneticAlgorithm::startAlgo() {
    createCities();
    createPopulation();
    population.findEliteSelection();
    double base_distance = population.getListTour().at(0)->determine_fitness();
    double best_distance = population.getListTour().at(0)->determine_fitness();
    int iterations = 0;
    double improvement = 0;
    while(iterations < ITERATIONS || improvement < IMPROVEMENT_FACTOR ){
        best_distance = evaluateTourFitness();
        improvement = (best_distance - base_distance) / base_distance;
        iterations++;
    }
    cout << "-----------------\n" << "Iterations: " << iterations << endl;
    cout << "Base distance: " << base_distance << endl;
    cout << "Best distance: " << best_distance << endl;
    cout << "Improvement: " << improvement << endl;
}
//initiate the master cities
void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(new City());
    }
}

// find the best fitness after crossover and mutate
double GeneticAlgorithm::evaluateTourFitness() {
//    cout << "Before merge \n" << population << endl;
    population.mergeToursCurrentPopulation();
//    cout << "After merge \n" << population << endl;
    population.findEliteSelection();
//    cout << "After find elite \n" << population << endl;
    return population.getListTour().at(0)->determine_fitness();
}

//create the population and shuffle each tour of SHUFFLES
void GeneticAlgorithm::createPopulation() {
    for(int i = 0; i < POPULATION_SIZE; i++){
        population.addListTour(new Tour(masterCities));
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
    while(!population.getListTour().empty()){
        delete population.getListTour().back();
        population.getListTour().pop_back();
    }
}