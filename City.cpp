//
// Created by jcheong on 2019-11-09.
//

#include <random>
#include "City.hpp"
long City::cityIDCounter = '1';

City::City() {
    default_random_engine randomEngine(time(0));
    uniform_real_distribution<double> distDoubleX(0.0,1000.0);
    uniform_real_distribution<double> distDoubleY(0.0,1000.0);
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

