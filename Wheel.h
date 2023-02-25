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
    int size;
    vector<int> wheel;

public:

    Wheel();
    Wheel(vector<int> wheel);

    int getCurrentWedge();
    int getSize();
    vector<int> getWheel();

    bool addWedge(int wedge);
    bool removeWedge(int wedge);

    void fillWheel();
    int spin();

    friend ostream& operator << (ostream& outs, Wheel& rhs);
};
#endif //M1OEP_HGSHERID_WHEEL_H
