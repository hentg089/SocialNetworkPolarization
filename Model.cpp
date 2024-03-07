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



Model::Model(int agentCount, int x, int n, std::unordered_map<std::string, FirstOrderDiscreteBelief>&& firstOrders,
             std::unordered_map<std::string, double>&& influences,
             std::vector<double>&& weightsFirstOrder, std::vector<double>&& weightsNthOrder){
    this->agentCount = agentCount;
    this->x = x;
    this->n = n;
    this->beliefs_t_first_order = std::move(firstOrders);
    this->influences = std::move(influences);
    this->firstOrderWeights = std::move(weightsFirstOrder);
    this->nOrderWeights = std::move(weightsNthOrder);
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
        if(beliefOrder == 1){
            calculateNewBeliefFirstOrder(beliefString, beliefOrder);
        }else{
            calculateNewBeliefNOrder(beliefString, beliefOrder);
        }
    }
}

void Model::calculateNewBeliefNOrder(std::string& beliefString, int& beliefOrder) {



}

void Model::calculateNewBeliefFirstOrder(std::string &beliefString, int &beliefOrder) {
    //because the cumulative is just and average we'll calculate individuals input from each agent then average
    double newBeliefCumulative = 0;
    for(int agent = 1; agent <= agentCount; ++agent){
        newBeliefCumulative += calculateNewBelief1OrderRelTo(beliefString, agent);
    }

    //basically just take the average after finding individual contributions - we can come back and optimize this
    beliefs_t_plus_1_first_order[beliefString] = FirstOrderDiscreteBelief(newBeliefCumulative / agentCount);
}

double Model::calculateNewBelief1OrderRelTo(std::string& beliefString, int agent){
    double cur = beliefs_t_first_order[beliefString].getBeliefValue();
    double res = cur;


    //dont actually need this shit because it's first order beoeif
//    std::vector<std::string>agentsForInfluence;
//    std::stringstream ss(beliefString);
//    std::string num;
//    std::getline(ss, num, 'B');
//    while(std::getline(ss, num, 'B')){
//        agentsForInfluence.push_back(num);
//    }
    std::stringstream ss(beliefString);
    std::string updatingNum;
    std::getline(ss, updatingNum, 'B');
    std::getline(ss, updatingNum, 'B');

    //now we need to factor in B(agent)
    res += firstOrderWeights[0] *
            influences[std::to_string(agent) + "," + updatingNum] *
            (beliefs_t_first_order["B" + std::to_string(agent)].getBeliefValue() - cur);

    //for BAGENTBKBk2Bk3 etc
    if(n > 1){
        for(int order = 2; order <= x && order <= n; ++order){
            int index = order - 1;
            //weight * interval len avg * change factor avg
            res += firstOrderWeights[index] *
                    (1 - pow((1.0/agentCount), index) * stringGenJFirst("B" + std::to_string(agent), order + 0, std::move(updatingNum), order + 0)) *
                    pow((1.0/agentCount), index) *
                    avgDifferenceGenFirst("B" + std::to_string(agent), order + 0, std::move(updatingNum), order + 0);
        }
    }

    //for B0Bk1Bk2...Bagent
    if(n > 1){

    }


    return res;

}

double Model::stringGenJFirst(std::string&& s, int&& order, std::string&& updatingNum, int&& originalOrder){
    //s gets passed with BJ so if order = 2 then we have to only add one extra layer so order > 1
    if(order > 1){
        double ret = 0;
        for(int i = 1; i <= agentCount; ++i){
            s += "B" + std::to_string(i);
            order -= 1;
            ret += stringGenJFirst(std::move(s), std::move(order),
                               std::move(updatingNum), std::move(originalOrder));
            order += 1;
            size_t truncatePoint = s.find_last_of('B');
            s = s.substr(0,truncatePoint);
        }

        return ret;
    }else{
        return beliefs_t[s].length();
    }
}

double Model::avgDifferenceGenFirst(std::string &&s, int &&order, std::string &&updatingNum, int &&originalOrder) {
    if(order > 1){
        double ret = 0;
        for(int i = 1; i <= agentCount; ++i){
            s += "B" + std::to_string(i);
            order -= 1;
            ret += stringGenJFirst(std::move(s), std::move(order),
                                   std::move(updatingNum), std::move(originalOrder));
            order += 1;
            size_t truncatePoint = s.find_last_of('B');
            s = s.substr(0,truncatePoint);
        }
    }else{
        double influence = 1;
        std::stringstream ss(s);
        std::string num;
        std::getline(ss, num, 'B');
        while(std::getline(ss, num, 'B')){
            influence *= influences[updatingNum + "," + num];
        }

        return influence * (beliefs_t[s].center() - beliefs_t_first_order["B" + updatingNum].getBeliefValue())
    }
}


double Model::getPolarizationValue() {
    return 0;
}