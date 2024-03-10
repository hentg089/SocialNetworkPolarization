//
// Created by markh on 3/9/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_WEIGHTSCHEMA_H
#define SOCIALNETWORKPOLARIZATION_WEIGHTSCHEMA_H


class WeightSchema {
private:
    //n is how many weights we want
    int weightCount;
    //sigma(a * r^i)
    //it is a necessity that a = 1-r for the sum of the weight to equal 1
    double a;
    double r;

public:
    WeightSchema(int weightCount, double a, double r);

    //indexed at 0
    double getIthWeight(int index);
};



#endif //SOCIALNETWORKPOLARIZATION_WEIGHTSCHEMA_H
