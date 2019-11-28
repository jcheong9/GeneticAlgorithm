//
// Created by jcheong on 2019-11-09.
//

#ifndef GENETICALGORITHM_TOUR_HPP
#define GENETICALGORITHM_TOUR_HPP


#include <vector>
#include "City.hpp"
const double MUTATION_RATE = 0.15;
using namespace std;
class Tour {
private:
    vector<City*> cityList;
    long tourID;
    //helper functions prototypes
    void swapping(Tour& a, Tour b);

public:
    //tour ids
    static long tourIDCounter;
    //constructors
    Tour() = default;
    explicit Tour(vector<City*> cityList);

    //function prototype
    double totalDistance() const;
    double determine_fitness() const;
    void print_tour_distance();
    double get_tour_distance();
    double get_distance_between_cities(City city1, City city2) const;
    bool contains_city(City city);
    void mutateCities(int a, int b);

    //setters and getters
    vector<City *> getCityList() const;
    void setCityList(vector<City *> cityList);
    long getTourId() const;

    //overloading operators
    Tour& operator=(Tour &m);
    friend ostream &operator << (ostream &os, const Tour &m);
    Tour& operator = (const Tour & m);
    //destructor
    ~Tour() = default;
};

#endif //GENETICALGORITHM_TOUR_HPP
