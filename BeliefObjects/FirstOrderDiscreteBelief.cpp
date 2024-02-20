//
// Created by markh on 2/20/2024.
//

#include "FirstOrderDiscreteBelief.h"

FirstOrderDiscreteBelief::FirstOrderDiscreteBelief() {
    this->beliefValue = 0.0;
}

FirstOrderDiscreteBelief::FirstOrderDiscreteBelief(double beliefValue) {
    this->beliefValue = beliefValue;
}

void FirstOrderDiscreteBelief::setBelief(double belief) {
    this->beliefValue = belief;
}

double FirstOrderDiscreteBelief::getBeliefValue() {
    return this->beliefValue;
}

