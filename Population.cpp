//
// Created by jcheong on 2019-11-09.
//

#include "Population.hpp"
//find the elite in the list of population.
void Population::findEliteSelection() {
    double bestFitness = listTour.at(0)->determine_fitness();
    vector<Tour* >::iterator itBegin = listTour.begin();
    vector<Tour* >::iterator itBestFit;
    for(itBegin; itBegin != listTour.end(); itBegin++){
        if(bestFitness > itBegin.operator*()->determine_fitness()){
            bestFitness = itBegin.operator*()->determine_fitness();
            itBestFit = itBegin;
        }
    }
    auto x = *itBestFit; // or std::move(*it)
    listTour.erase(itBestFit);
    listTour.insert(listTour.begin(), x );
}
//constructor
Population::Population(vector<Tour *> listTour) {
    this->listTour = listTour;
}
//setters and getters
vector<Tour *> Population::getListTour() const{
    return listTour;
}

void Population::setListTour(const vector<Tour *> listTour) {
    Population::listTour = listTour;
}
//print population information
ostream &operator<<(ostream &os, const Population &m) {
    for(vector<Tour>::size_type i = 0; i < m.listTour.size(); i++) {
        os << "Tour " + to_string(m.listTour.at(i)->getTourId()) + " ";
        os << to_string(m.listTour.at(i)->determine_fitness()) + "cost\n";
    }
    return os;
}
