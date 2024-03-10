#include <iostream>
#include "Model.h"
#include "Weights/WeightSchema.h"

int main() {
//    std::vector<double> weights_first = {0.9,0.05,0.05};
//    std::vector<double> weights_higher = {0.9,0.05,0.04, 0.01};
//    std::unordered_map<std::string, FirstOrderDiscreteBelief>
//            firstOrderBeliefs = {{"B1" , FirstOrderDiscreteBelief(0.6)},
//                                                                 {"B2", FirstOrderDiscreteBelief(0.5)}};
//    std::unordered_map<std::string, double> influence = {{"1,2", 0.8}, {"2,1", 0.6}};
//
//
//    int x = 2;
//    int n = 2;
//    int agentCount = 2;
//
//
//    Model p(agentCount, x, n, std::move(firstOrderBeliefs), std::move(influence),
//            std::move(weights_first), std::move(weights_higher));
//
//    p.avgDifferenceGenSecond("BV",3,"1",3, "5");
//
    WeightSchema p(2, 0.9, 0.1);
    std::cout << p.getIthWeight(1) << std::endl;
    std::cout << p.getIthWeight(2) << std::endl;











    return 0;
}
