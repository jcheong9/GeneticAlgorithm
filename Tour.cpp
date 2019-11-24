//
// Created by jcheong on 2019-11-09.
//

#include <random>
#include <algorithm>
#include "Tour.hpp"
#include <cmath>
#include <iostream>
//instantiate random device
random_device randDevice;
// instantiate random engine
auto rn = default_random_engine{};
//tour ID counter
long Tour::tourIDCounter = 0;

//constructor
Tour::Tour(vector<City *> cityList) {
    this->cityList = cityList;
    this->tourID = tourIDCounter++;
}

//find the fitness of the tour
double Tour::determine_fitness() const {
    return (1 / totalDistance()) * 100000;
}

//calculating the total distance
double Tour::totalDistance() const {
    double total = 0;
    double xComb ;
    double yComb ;

    for(vector<City>::size_type i = 1; i < cityList.size(); i++){
        total += get_distance_between_cities( *cityList.at(i), *cityList.at(i - 1));
    }
    return total;
}

//get the distance between two cities
double Tour::get_distance_between_cities(City city1, City city2) const {
    return sqrt(pow((city1.getX() - city2.getX()),2) +
                pow((city1.getY() - city2.getY()),2));
}

// get the distance and print and display
void Tour::get_tour_distance() {
    for(vector<City>::size_type i = 1; i < cityList.size(); i++){
        cout << "Cities distance between in this tour list CityID: " << cityList.at(i)->getCityId() << " & CityID: "
        << cityList.at(i - 1)->getCityId() << " : "
        << get_distance_between_cities( *cityList.at(i), *cityList.at(i - 1)) << endl;
    }
}

//find if the city in this tour
bool Tour::contains_city(City city) {
    for(auto it = cityList.begin(); it != cityList.end(); it++){
        if(it.operator*()->getCityId() == city.getCityId()){
            return true;
        }
    }
    return false;
}

//overloading the equal
Tour &Tour::operator=(const Tour & m) {
    swapping(*this, m);
    return *this;
}

//helper function swap the two objects's data members
void Tour::swapping(Tour& a, Tour b) {
    using std::swap;
    swap(a.cityList,a.cityList);
    swap(a.tourID,a.tourID);
}
void Tour::mutateCities(int a, int b) {
    auto tmp = *cityList.at(a);
    *cityList.at(a) = *cityList.at(b);
    *cityList.at(b) = tmp;
}
//setters and getters
vector<City *> Tour::getCityList() const{
    return cityList;
}
//set the city list
void Tour::setCityList(const vector<City *> cityList) {
    Tour::cityList = cityList;
}
//get the tour id
long Tour::getTourId() const {
    return tourID;
}
//equal overloading
Tour& Tour::operator=(Tour &m) {
    using std::swap;
    swap(this->cityList,m.cityList);
    swap(this->tourID, m.tourID);
};

//prints the list of cities in tour
ostream &operator<<(ostream &os, const Tour &m) {
    os << "Tour ID: " + to_string(m.tourID) << endl;
    os << "Fitness: " + to_string(m.determine_fitness()) << endl;
    os << "Total distance tour: " + to_string(m.totalDistance()) << endl;
    for(vector<City>::size_type i = 0; i < m.cityList.size(); i++){
        os << "City ID: " + to_string(m.cityList.at(i)->getCityId()) + " ";
        os << "x: " +to_string(m.cityList.at(i)->getX()) + " ";
        os << "y: " +to_string(m.cityList.at(i)->getY()) << endl;
    }
    return os;
}


















