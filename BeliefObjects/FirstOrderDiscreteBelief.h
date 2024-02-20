//
// Created by markh on 2/20/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_FIRSTORDERDISCRETEBELIEF_H
#define SOCIALNETWORKPOLARIZATION_FIRSTORDERDISCRETEBELIEF_H

#include "Belief.h"


class FirstOrderDiscreteBelief : public Belief{
private:
    double beliefValue;
public:
    FirstOrderDiscreteBelief();

    FirstOrderDiscreteBelief(double beliefValue);

    void setBelief(double belief);

    double getBeliefValue();
};


#endif //SOCIALNETWORKPOLARIZATION_FIRSTORDERDISCRETEBELIEF_H
