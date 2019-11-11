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
private:
    vector<Tour*> listTour;
public:
    //constructors
    Population() = default;
    explicit Population(vector<Tour*> listTour);

    //function prototypes
    void findEliteSelection();
    Tour select_parents();
    void improvement_factor();
    Tour crossover();
    void mutate();

    //setters and getters
    vector<Tour *> getListTour() const;
    void setListTour(vector<Tour *> listTour);

    //overloading operators
    friend ostream &operator << (ostream &os, const Population &m);

    //destructors
    ~Population() = default;
};
#endif //GENETICALGORITHM_POPULATION_HPP
