//
// Created by markh on 2/20/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_INTERVAL_H
#define SOCIALNETWORKPOLARIZATION_INTERVAL_H

#include "Belief.h"


class Interval : public Belief {
private:
    double l;
    double r;
public:
    Interval();
    Interval(double l, double r);

    double getR();
    double getL();

    void setR(double r);
    void setL(double l);

    double center();

    double length();
};


#endif //SOCIALNETWORKPOLARIZATION_INTERVAL_H
