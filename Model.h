//
// Created by markh on 2/20/2024.
//

#ifndef SOCIALNETWORKPOLARIZATION_MODEL_H
#define SOCIALNETWORKPOLARIZATION_MODEL_H

#include "BeliefObjects/Belief.h"
#include "BeliefObjects/Interval.h"
#include "BeliefObjects/FirstOrderDiscreteBelief.h"

#include <unordered_map>
#include <vector>
#include <memory>
#include <iostream>
#include <sstream>

class Model{
private:
    //we will have p agents, 1-p. Higher order belief can be thought of as a chain ie:
    //1 believes 2 belives 1 believs 3 believes etc and can bre represented with an int: 1213...
    std::unordered_map<std::string, std::unique_ptr<Belief>> beliefs_t;
    std::unordered_map<std::string, std::unique_ptr<Belief>> beliefs_t_plus_1;
    std::unordered_map<std::string, double> influences;
    int n;
    int x;
    int agentCount;

    //given a belief order it will calculate all the new beliefs at that level
    void calculateNewBeliefFirstOrder(std::string&, int&);
    double calculateNewBelief1OrderRelTo(std::string, int agent);

    void calculateNewBeliefNOrder(std::string&, int&);

    double getPolarizationValue();
public:
    void calculateOrderBeliefs(int& beliefOrder, int xIter, std::string& belief);

    Model();
    Model(int agentCount, int x, int n);

    Model(int agentCount, int x, int n, std::unordered_map<std::string, std::unique_ptr<Belief>>&& firstOrders,
          std::unordered_map<std::string, double>&& influences);

    std::vector<double> runSimulation(int tSteps);



};


#endif //SOCIALNETWORKPOLARIZATION_MODEL_H
