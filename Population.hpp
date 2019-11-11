//
// Created by jcheong on 2019-11-09.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include <utility>
#include "Tour.hpp"


using namespace std;
class Population{
const int POPULATION_POOL_SIZE = 5;
const int NUMBER_OF_ELITES = 1;
private:
    int NUMBER_OF_PARENTS = 0;
    vector<Tour*> listTour;
public:
    //constructors
    Population() = default;
    explicit Population(vector<Tour*> listTour);

    //function prototypes
    void findEliteSelection();
    Tour select_parents();
    Tour crossover();
    void mergeToursCurrentPopulation();
    void mutate();

    //setters and getters
    vector<Tour *> getListTour() const;
    void addListTour(Tour* tour);
    void setListTour(int index, Tour tour);
    int getNumberOfParents() const;

    //overloading operators
    friend ostream &operator << (ostream &os, const Population &m);

    //destructors
    ~Population() = default;
};
#endif //GENETICALGORITHM_POPULATION_HPP
