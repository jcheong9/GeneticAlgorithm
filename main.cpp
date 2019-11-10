#include <iostream>
#include <vector>
#include "City.hpp"
#include "Tour.hpp"

using namespace std;
int main() {
    City a {};
    City b {};
    City c {};
    cout << "City ID: " << a.getCityId() << " a x:" << a.getX() << " a y:" << a.getY() << endl;
    cout << "City ID: " << b.getCityId() << " b x:" << b.getX() << " b y:" << b.getY() << endl;
    cout << "City ID: " << c.getCityId() << " c x:" << c.getX() << " c y:" << c.getY() << endl;
    vector<City*> masterCities{&a, &b, &c};

    Tour firstTour{masterCities};
    cout << firstTour.getCityList().at(0)->getX() << endl;
    cout << firstTour.getCityList().at(1)->getX() << endl;
    cout << firstTour.getCityList().at(2)->getX() << endl;

    cout << firstTour;
    return 0;
}