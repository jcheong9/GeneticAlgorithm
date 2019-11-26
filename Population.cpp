//
// Created by jcheong on 2019-11-09.
//

#include <random>
#include "Population.hpp"
#include <iostream>
#include <algorithm>
//instantiate random device
default_random_engine rdEngine(time(0));
// instantiate random engine
random_device rd;


//find the elite in the list of population.
void Population::findEliteSelection() {
    double bestFitness = listTour.at(0).determine_fitness();
    int bestIndex = 0;
    for(int i = 0; i < listTour.size(); i++) {
        if (bestFitness < listTour.at(i).determine_fitness()) {
            bestFitness = listTour.at(i).determine_fitness();
            bestIndex = i;
        }
    }
    Tour tmp = listTour.at(0);
    listTour.at(0) = listTour.at(bestIndex);
    listTour.at(bestIndex) = tmp;
}

//crossing two parent return a child tour.
Tour Population::crossover() {
    //pick the two parent
    Tour parentA = select_parents();
    Tour parentB = select_parents();

    mt19937 generatorInt(rd());
    uniform_int_distribution<> distInt(0, parentA.getCityList().size());
    vector<City* > tmpCitiesList;
    for(vector<Tour*>::size_type i = 0; i < distInt(generatorInt); i++){
        tmpCitiesList.push_back(parentA.getCityList().at(i));
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

    return Tour{tmpCitiesList};
}

//pick POPULATION_POOL_SIZE of original population and pick the fittest tour as parent
Tour Population::select_parents() {
    mt19937 generatorInt(rd());
    uniform_int_distribution<> distInt(0, listTour.size()-1);
    //create sets of tours
    vector<Tour> tempTour;
    for(int i = 0; i < POPULATION_POOL_SIZE; i++){
        tempTour.push_back(listTour.at(distInt(generatorInt)));
    }
    double bestFitness = tempTour.at(0).determine_fitness();
    int index = 0;
    for(vector<Tour>::size_type i = 0; i < tempTour.size(); i++){
        if(tempTour.at(i).determine_fitness() > bestFitness){
            index = i;
        }
    }
    return tempTour.at(index);
}

//merge the children to current population expect the elite.
void Population::mergeToursCurrentPopulation() {
    vector<Tour> tmp;
    tmp.push_back(listTour.at(0));

    for(vector<Tour>::size_type i = NUMBER_OF_ELITES; i < listTour.size(); i++) {
            tmp.push_back(crossover());
    }

    listTour.clear();
    listTour = tmp;
}

//mutate of randomly 20 to 30 of the total population and mutate at MUTATION_RATE. Mutation swap the adjacent city.
void Population::mutate() {
    mt19937 generatorInt(rd());
    uniform_int_distribution<> distInt(NUMBER_OF_ELITES, listTour.size() - 1);
    uniform_real_distribution<double> distMutate(0.0,1);
    uniform_real_distribution<double> distPopulationMutation(0.2,0.3);

    for(vector<Tour*>::size_type i = 1; i < listTour.size() * distPopulationMutation(rdEngine); i++) {
        int indexTour = distInt(generatorInt);
        vector<City*> listCityTmp = listTour.at(indexTour).getCityList();
        for (vector<City *>::size_type j = 1; j < listTour.at(indexTour).getCityList().size(); j++) {

            if (distMutate(rdEngine) < MUTATION_RATE ) {
                int nextInd = j - 1;
                City* tmp = listCityTmp.at(j);
                listCityTmp.at(j) = listCityTmp.at(nextInd);
                listCityTmp.at(nextInd) = tmp;
            }
        }
        listTour.at(indexTour).setCityList(listCityTmp);
    }
}

//constructor
Population::Population(vector<Tour > listTour) {
    this->listTour = listTour;
}

//setters and getters
vector<Tour > Population::getListTour() const{
    return listTour;
}

int Population::getNumberOfParents() const {
    return NUMBER_OF_PARENTS;
}

void Population::addListTour(Tour tour) {
    listTour.push_back(tour);
}

//print population information
ostream &operator<<(ostream &os, const Population &m) {
    for(int i = 0; i < m.listTour.size(); i++) {
        os << "Tour " + to_string(m.listTour.at(i).getTourId()) + " \n";
        os << to_string(m.listTour.at(i).determine_fitness()) + " cost\n";
        os << m.listTour.at(i) << endl;
        os << "---------------------------------------------" << endl;
    }
    return os;
}








