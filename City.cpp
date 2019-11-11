//
// Created by jcheong on 2019-11-09.
//


#include "City.hpp"
long City::cityIDCounter = '10';
default_random_engine City::randomEngine(time(0));
//constructor
City::City() {
    uniform_real_distribution<double> distDoubleX(0.0,MAP_BOUNDARY);
    uniform_real_distribution<double> distDoubleY(0.0,MAP_BOUNDARY);
    x = distDoubleX(randomEngine);
    y = distDoubleY(randomEngine);
    cityID = cityIDCounter++;
}

double City::getX() const {
    return x;
}

void City::setX(double x) {
    City::x = x;
}

double City::getY() const {
    return y;
}

void City::setY(double y) {
    City::y = y;
}

long City::getCityId() const {
    return cityID;
}

void City::setCityId(long cityId) {
    cityID = cityId;
}

void City::swapping(City& a, City b) {
    using std::swap;
    swap(a.cityID,b.cityID);
    swap(a.x,b.x);
    swap(a.y,b.y);
}

City &City::operator=(const City &m)  {
    swapping(*this, m);
    return *this;
}

