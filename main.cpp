#include <iostream>
#include <vector>
#include "City.hpp"
#include "Tour.hpp"
#include "Population.hpp"

using namespace std;
int main() {
    City a {};
    City b {};
    City c {};
    City d {};
    City e {};
    cout << "City ID: " << a.getCityId() << " a x:" << a.getX() << " a y:" << a.getY() << endl;
    cout << "City ID: " << b.getCityId() << " b x:" << b.getX() << " b y:" << b.getY() << endl;
    cout << "City ID: " << c.getCityId() << " c x:" << c.getX() << " c y:" << c.getY() << endl;
    cout << "City ID: " << d.getCityId() << " c x:" << d.getX() << " c y:" << d.getY() << endl;
    vector<City*> masterCities{&a, &b, &c, &d, &e};

    Tour tour1{masterCities};
    Tour tour2{masterCities};
    Tour tour3{masterCities};
    Tour tour4{masterCities};
    Tour tour5{masterCities};
    Tour tour6{masterCities};
    Tour tour7{masterCities};
    Tour tour8{masterCities};
    Tour tour9{masterCities};
    Tour tour10{masterCities};

    vector<Tour *> populationList{&tour1, &tour2, &tour3, &tour4, &tour6, &tour7, &tour8, &tour9, &tour10};
    tour1.get_tour_distance();


    Population originalPopulation(populationList);
    originalPopulation.findEliteSelection();
    cout << originalPopulation;
    return 0;
}

