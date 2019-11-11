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
    void swapping(City& a, City b);
public:
    //cityIDCounter for the id generator
    static long cityIDCounter;
    //constructor
    City();
    //operator overloading
    City& operator = (const City &m);

    //setters and getters
    double getX() const;
    void setX(double x);
    double getY() const;
    void setY(double y);
    long getCityId() const;
    void setCityId(long cityId);

    ~City() = default;

};
#endif //GENETICALGORITHM_CITY_HPP
