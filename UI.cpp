//
// Created by jcheong on 2019-11-11.
//

#include <iostream>
#include <sstream>
#include "UI.hpp"
using namespace std;
void UI::start() {
    int citiesInTour;
    int populationSize;

    if(promptUserCities( citiesInTour) && promptUserPopulation(populationSize)){

    }else{
        cout << "Program ends input is not a number or equal to zero";
    }
}

bool UI::promptUserCities(int citiesInTour) {
    stringstream stream;
    string str = "";
    stream.clear();
    cout << "Enter the cities in tour greater than 2: ";
    getline(cin, str);
    stream.str(str);
    stream >> citiesInTour;
    return citiesInTour > 1;
}

bool UI::promptUserPopulation(int populationSize) {
    stringstream stream;
    string str = "";
    stream.clear();
    cout << "Enter the population size (number of tour) greater than 2: ";
    getline(cin, str);
    stream.str(str);
    stream >> populationSize;
    return populationSize > 1;
}
