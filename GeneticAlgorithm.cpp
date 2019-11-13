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
    Tour* base_tour = population.getListTour().at(0);
    double base_distance = population.getListTour().at(0)->totalDistance();
    double best_distance = population.getListTour().at(0)->totalDistance();
    int iterations = 0;
    double improvement = 0.0;
    bool achieved = false;
    while(iterations < ITERATIONS ){
        if(improvement > IMPROVEMENT_FACTOR){
            achieved = true;
            break;
        }
        evaluateTourFitness();
        cout << "-----------------\n" << "Iteration Number: " << iterations << endl;
        best_distance = population.getListTour().at(0)->totalDistance();
        cout << "Best distance: " << best_distance << endl;
        improvement = (base_distance - best_distance) / base_distance;
        cout << "Current Improvement: " << improvement << endl;
        iterations++;
    }
    printFinalReport(achieved, iterations, base_distance, best_distance, improvement, *base_tour);
}

//initiate the master cities
void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(new City());
    }
}

// find the best fitness after crossover and mutate
double GeneticAlgorithm::evaluateTourFitness() {
    population.mergeToursCurrentPopulation();
    population.findEliteSelection();
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

//print the final report after the genetic algorithm is completed.
void GeneticAlgorithm::printFinalReport(bool achieved, int iterations, double base_distance, double best_distance,
                                        double improvement, Tour base_tour) {
    cout << "-----------------\n" << "Number Iterations: " << iterations << endl;
    cout << "Base distance: " << base_distance << endl;
    cout << "Best distance: " << best_distance << endl;
    cout << "Improvement factor achieved: ";
    string str = achieved ? ("true\n") : ("false\n");
    cout << str;
    cout << "Improvement: " << improvement << endl;
    cout << "Base tour route: \n" << base_tour << endl;
    cout << "Best route take: \n" << *population.getListTour().at(0) << endl;
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


