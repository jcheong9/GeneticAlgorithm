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
    cout << "----------------"<< endl;
    Tour tour1{masterCities};
    tour1.shuffle_cities();
    Tour tour2{masterCities};
    tour2.shuffle_cities();
    Tour tour3{masterCities};
    tour3.shuffle_cities();
    Tour tour4{masterCities};
    tour4.shuffle_cities();
    Tour tour5{masterCities};
    tour5.shuffle_cities();
    Tour tour6{masterCities};
    tour6.shuffle_cities();
    Tour tour7{masterCities};
    tour7.shuffle_cities();
    Tour tour8{masterCities};
    tour8.shuffle_cities();
    Tour tour9{masterCities};
    tour9.shuffle_cities();
    Tour tour10{masterCities};
    tour10.shuffle_cities();


    cout << tour1 << endl;
    cout << tour2 << endl;
    cout << tour3 << endl;
    cout << tour4 << endl;
    cout << tour5 << endl;
    cout << tour6 << endl;
    cout << tour7 << endl;
    cout << tour8 << endl;
    cout << tour9 << endl;
    cout << tour10 << endl;


    vector<Tour *> populationList{&tour1, &tour2, &tour3, &tour4, &tour6, &tour7, &tour8, &tour9, &tour10};
//    tour1.get_tour_distance();

    Population originalPopulation(populationList);
    originalPopulation.findEliteSelection();
    cout << originalPopulation << endl;
//    originalPopulation.select_parents();
    cout << "Cross" << endl;
//    cout << originalPopulation.select_parents();
    cout << originalPopulation.crossover();

    return 0;
}

