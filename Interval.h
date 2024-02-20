//
// Created by markh on 2/20/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_INTERVAL_H
#define SOCIALNETWORKPOLARIZATION_INTERVAL_H


class Interval {
private:
    double l;
    double r;
public:
    Interval();
    Interval(double l, double r);

    double getR();
    double getL();

    double setR(double r);
    double setL(double l);

    double center();

    double length();
};


#endif //SOCIALNETWORKPOLARIZATION_INTERVAL_H
