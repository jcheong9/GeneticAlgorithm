//
// Created by jcheong on 2019-11-09.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include <utility>
#include "Tour.hpp"
#include <random>

using namespace std;
class Population{
const int POPULATION_POOL_SIZE = 5;
const int NUMBER_OF_ELITES = 1;
const int NUMBER_OF_PARENTS = 2;
private:
    vector<Tour> listTour;
public:

    //constructors
    Population() = default;
    explicit Population(vector<Tour> listTour);

    //function prototypes
    void findEliteSelection();
    Tour select_parents();
    Tour crossover();
    void mergeToursCurrentPopulation();
    void mutate();

    //setters and getters
    vector<Tour > getListTour() const;
    void addListTour(Tour tour);
    int getNumberOfParents() const;

    //overloading operators
    friend ostream &operator << (ostream &os, const Population &m);

    //destructors
    ~Population() = default;
};
#endif //GENETICALGORITHM_POPULATION_HPP
