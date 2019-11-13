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
const double POPULATION_MUTATION = 0.3;
private:
    int NUMBER_OF_PARENTS = 0;
    vector<Tour*> listTour;
public:
    // instantiate random engine
    random_device rd;

    //constructors
    Population() = default;
    explicit Population(vector<Tour*> listTour);

    //function prototypes
    void findEliteSelection();
    Tour select_parents();
    Tour* crossover();
    void mergeToursCurrentPopulation();
    void mutate();

    //setters and getters
    vector<Tour *> getListTour() const;
    void addListTour(Tour* tour);
    int getNumberOfParents() const;

    //overloading operators
    friend ostream &operator << (ostream &os, const Population &m);

    //destructors
    ~Population();
};
#endif //GENETICALGORITHM_POPULATION_HPP
