//
// Created by jcheong on 2019-11-09.
//

#ifndef GENETICALGORITHM_POPULATION_HPP
#define GENETICALGORITHM_POPULATION_HPP

#include <utility>

#include "Tour.hpp"
using namespace std;
class Population{
private:
    vector<Tour*> listTour;
public:
    Population() = default;
    Population(vector<Tour*> listTour) : listTour{std::move(listTour)} {}
    void findElite();
    ~Population() = default;
};
#endif //GENETICALGORITHM_POPULATION_HPP
