//
// Created by jcheong on 2019-11-09.
//

#include <random>
#include <iostream>
#include "Population.hpp"
//instantiate random device
random_device rd;
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
    swap(listTour.front(), *itBestFit);
}
//crossing two parent return a child tour.
Tour Population::crossover() {
    Tour parentA = select_parents();
    Tour parentB = select_parents();
    vector<City*> tmpCitiesList;

    for(vector<Tour*>::size_type i = 0; i < parentA.getCityList().size(); i++){
        if(i < parentA.getCityList().size()/2)
            tmpCitiesList.push_back(parentA.getCityList().at(i));
        else
            break;
    }
    //copy b cities to temp city list
    bool foundDuplicate;
    for(vector<Tour*>::size_type i = 0; i < parentB.getCityList().size(); i++){
        foundDuplicate = false;
        for(vector<Tour*>::size_type j = 0; j < tmpCitiesList.size(); j++) {
            if(tmpCitiesList.at(j)->getCityId() == parentB.getCityList().at(i)->getCityId()) {
                foundDuplicate = true;
                break;
            }
        }
        if(!foundDuplicate && tmpCitiesList.size() < parentB.getCityList().size()){
            tmpCitiesList.push_back(parentB.getCityList().at(i));
        }
    }
    Tour temp{tmpCitiesList};
    return temp;

}
//pick POPULATION_POOL_SIZE of original population and pick the fittest tour as parent
Tour Population::select_parents() {
    mt19937 generatorInt(rd());
    uniform_int_distribution<> distInt(0, listTour.size()-1);
    //create sets
    vector<Tour*> tempTour;
    for(int i = 0; i < POPULATION_POOL_SIZE; i++){
        tempTour.push_back(listTour.at(distInt(generatorInt)));
    }
    double bestFitness = tempTour.at(0)->determine_fitness();
    int index = 0;
    for(vector<Tour*>::size_type i = 1; i < tempTour.size(); i++){
        if(tempTour.at(i)->determine_fitness() > bestFitness){
            index = i;
        }
    }
    return *tempTour.at(index);
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

