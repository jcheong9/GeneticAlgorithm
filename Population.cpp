//
// Created by jcheong on 2019-11-09.
//

#include "Population.hpp"

void Population::findElite() {
    double bestFitness = listTour.at(0)->getFitnessRating();
    for(auto it = listTour.begin(); it != listTour.end(); it++){
        if(bestFitness > it.operator*()->getFitnessRating()){
            bestFitness = it.operator*()->getFitnessRating();
            auto x = *it; // or std::move(*it)
            listTour.erase(it);
            listTour.insert(listTour.begin(), x );
        }
    }

}
