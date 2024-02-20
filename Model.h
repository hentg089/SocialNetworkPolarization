//
// Created by markh on 2/20/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_MODEL_H
#define SOCIALNETWORKPOLARIZATION_MODEL_H

#include <unordered_map>

class Model {
private:
    std::unordered_map<double, Interval> =
    int n;
    int x;
public:
    Model();
    Model(int x, int y);
};


#endif //SOCIALNETWORKPOLARIZATION_MODEL_H
