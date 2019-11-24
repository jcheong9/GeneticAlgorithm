//
// Created by jcheong on 2019-11-11.
//

#include <iostream>
#include <algorithm>
#include "GeneticAlgorithm.hpp"
//constructor
GeneticAlgorithm::GeneticAlgorithm(int city, int popsize) : CITIES_IN_TOUR{city}, POPULATION_SIZE{popsize}{
    startAlgo();
}
//starts the algorithm, prints each iteration and the final report.
void GeneticAlgorithm::startAlgo() {
    createCities();
    createPopulation();
    population.findEliteSelection();
    Tour base_tour = population.getListTour().at(0);
    double base_distance = population.getListTour().at(0).totalDistance();
    double best_distance = population.getListTour().at(0).totalDistance();
    int iterations = 0;
    double improvement = 0.0;
    bool achieved = false;

    while(iterations < ITERATIONS ){
        population.mergeToursCurrentPopulation(); //cross and merge the children with the new list
        population.mutate();
        population.findEliteSelection();

        best_distance = population.getListTour().at(0).totalDistance();
        improvement = best_distance / base_distance;
        if(improvement <= IMPROVEMENT_FACTOR){
            achieved = true;
            break;
        }
        cout << "-----------------\n" << "Iteration Number: " << iterations << endl;
        cout << "Best distance: " << best_distance << endl;
        cout << "Current Improvement: " << 1.0-improvement << endl;
        iterations++;
    }

    printFinalReport(achieved, iterations, base_distance, best_distance, improvement, base_tour);
}

//initiate the master cities
void GeneticAlgorithm::createCities() {
    for(int i = 0; i < CITIES_IN_TOUR; i++ ){
        masterCities.push_back(new City());
    }
}

//create the population and shuffle each tour of SHUFFLES
void GeneticAlgorithm::createPopulation() {
    vector<City*> tmpList = masterCities;
    auto rn = default_random_engine{};
    for(int i = 0; i < POPULATION_SIZE; i++){
        for(int j = 0; j < SHUFFLES; j ++){
            shuffle(tmpList.begin(),tmpList.end(),rn);
        }
        population.addListTour(Tour{tmpList});
    }
}

//print the final report after the genetic algorithm is completed.
void GeneticAlgorithm::printFinalReport(bool achieved, int iterations, double base_distance, double best_distance,
                                        double improvement, Tour base_tour) {
    cout << "---------Final Report---------\n" << "Number Iterations: " << iterations << endl;
    cout << "Base distance: " << base_distance << endl;
    cout << "Best distance: " << best_distance << endl;
    cout << "Improvement factor achieved: ";
    string str = achieved ? ("true\n") : ("false\n");
    cout << str;
    cout << "Improvement: " << 1.0-improvement << endl;
    cout << "Base tour route: \n" << base_tour << endl;
    cout << "Best route take: \n" << population.getListTour().at(0) << endl;
}
//destructor delete the allocated memories
GeneticAlgorithm::~GeneticAlgorithm() {
    while(!masterCities.empty()){
        delete masterCities.back();
    }
        masterCities.clear();
}


