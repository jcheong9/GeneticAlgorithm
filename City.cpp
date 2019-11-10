//
// Created by jcheong on 2019-11-09.
//

#include <random>
#include "City.hpp"
long City::cityIDCounter = '1000';

City::City() {
    default_random_engine genertor(time(0));
    uniform_real_distribution<double> distDoubleX(0.0,1000.0);
    uniform_real_distribution<double> distDoubleY(0.0,1000.0);
    x = distDoubleX(genertor);
    y = distDoubleY(genertor);
    cityID = cityIDCounter++;
}

