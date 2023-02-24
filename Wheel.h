//
// Created by Hannah Sheridan on 2/24/23.
//

#ifndef M1OEP_HGSHERID_WHEEL_H
#define M1OEP_HGSHERID_WHEEL_H

#include <iostream>
#include <vector>

using namespace std;

class Wheel {
private:
    int wedge;
    vector<int> wheel;

public:

    Wheel();
    void fillWheel();

    int spin();

    friend ostream& operator << (ostream& outs, Wheel& rhs);
};
#endif //M1OEP_HGSHERID_WHEEL_H
