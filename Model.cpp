//
// Created by markh on 2/20/2024.
//

#include "Model.h"

Model::Model() {
    n = 1;
    x = 1;
}

Model::Model(int agentCount, int x, int n) {
    this->agentCount = agentCount;
    this->x = x;
    this->n = n;
}

Model::Model(int agentCount, int x, int n, std::unordered_map<std::string, std::unique_ptr<Belief>>&& firstOrders,
             std::unordered_map<std::string, double>&& influences){
    this->agentCount = agentCount;
    this->x = x;
    this->n = n;
    this->beliefs_t = std::move(firstOrders);
    this->influences = std::move(influences);
}

std::vector<double> Model::runSimulation(int tSteps) {
    std::vector<double> polarizationValues;
    //going to return the vector of polarization values - reserve to safe time
    polarizationValues.reserve(tSteps + 1);

    //get the initial polarization value
    polarizationValues.push_back(getPolarizationValue());

    std::string beliefString = "";
    //iterate through every time values *calculate polarization at every time
    for(int i = 0;i < tSteps; ++i){
        //calculate the new beliefs at every level
        for(int j = 1; j <= x; ++j){
            calculateOrderBeliefs(j, j, beliefString);
        }
        //after calculating we want to get the new polarization value
        polarizationValues.push_back(getPolarizationValue());

        //want to update our polarization map so we move the next time step
        beliefs_t = std::move(beliefs_t_plus_1);
        beliefs_t_plus_1.clear();
    }

    return polarizationValues;
}

void Model::calculateOrderBeliefs(int& beliefOrder, int xIter, std::string& beliefString) {
    if(xIter != 0){
        for(int i = 1; i <= agentCount; ++i){
            beliefString += "B" + std::to_string(i);
            calculateOrderBeliefs(beliefOrder, xIter - 1, beliefString);
            size_t truncatePoint = beliefString.find_last_of('B');
            beliefString = beliefString.substr(0,truncatePoint);
        }
    }else{
        calculateNewBelief(beliefString);
    }
}

void Model::calculateNewBelief(std::string& beliefString) {
    std::cout << beliefString <<  std::endl;
}

double Model::getPolarizationValue() {
    return 0;
}