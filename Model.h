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
    //WE HAVE A HASHMAP FOR CURRENT FIRST ORDER, T + 1 FIRTST ORDER, CURRENT N ORDER AND T+1 N ORDER
    //WE SEPERATE IN ORDER TO AVOID POLYMORPHISM
    std::unordered_map<std::string, FirstOrderDiscreteBelief> beliefs_t_first_order;
    std::unordered_map<std::string, FirstOrderDiscreteBelief> beliefs_t_plus_1_first_order;
    std::unordered_map<std::string, Interval> beliefs_t;
    std::unordered_map<std::string, Interval> beliefs_t_plus_1;
private:
    std::unordered_map<std::string, double> influences;

    int n;
    int x;
    int agentCount;

    std::vector<double> firstOrderWeights;
    std::vector<double> nOrderWeights;
private:
    //given a belief order it will calculate all the new beliefs at that level
    void calculateOrderBeliefs(int& beliefOrder, int xIter, std::string& beliefString);

    void calculateNewBeliefFirstOrder(std::string&, int&);


    void calculateNewBeliefNOrder(std::string&, int&);

    double getPolarizationValue();
private:
    double stringGenJFirst(std::string&&, int&&, std::string&&, int&&);
    double avgDifferenceGenFirst(std::string&&, int&&, std::string&&, int&&);

    double stringGenJSecond(std::string&&, int&&, std::string&&, int&&);
    double avgDifferenceGenSecond(std::string&&, int&&, std::string&&, int&&);

public:
    double calculateNewBelief1OrderRelTo(std::string&, int agent);


    Model();
    Model(int agentCount, int x, int n);

    Model(int agentCount, int x, int n, std::unordered_map<std::string, FirstOrderDiscreteBelief>&& firstOrders,
          std::unordered_map<std::string, double>&& influences,
          std::vector<double>&& weightsFirstOrder, std::vector<double>&& weightsNthOrder);

    std::vector<double> runSimulation(int tSteps);


};


#endif //SOCIALNETWORKPOLARIZATION_MODEL_H
