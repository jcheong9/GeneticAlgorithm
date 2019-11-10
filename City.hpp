//
// Created by jcheong on 2019-11-09.
//

#ifndef GENETICALGORITHM_CITY_HPP
#define GENETICALGORITHM_CITY_HPP

#include <string>
using namespace std;
class City{
private:
    double x;
    double y;
    long cityID;
public:
    //cityIDCounter for the id generator
    static long cityIDCounter;
    City();
    ~City() = default;

};
#endif //GENETICALGORITHM_CITY_HPP
