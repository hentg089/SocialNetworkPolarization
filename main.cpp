#include <iostream>
#include "Model.h"

int main() {
    std::vector<double> weights_first = {0.9,0.05,0.05};
    std::vector<double> weights_higher = {0.9,0.05,0.04, 0.01};
    std::unordered_map<std::string, FirstOrderDiscreteBelief>
            firstOrderBeliefs = {{"B1" , FirstOrderDiscreteBelief(0.6)},
                                                                 {"B2", FirstOrderDiscreteBelief(0.5)}};
    std::unordered_map<std::string, double> influence = {{"1,2", 0.8}, {"2,1", 0.6}};


    int x = 2;
    int n = 2;
    int agentCount = 2;


    Model p(agentCount, x, n, std::move(firstOrderBeliefs), std::move(influence),
            std::move(weights_first), std::move(weights_higher));
    std::string h = "B1";
    std::cout << p.calculateNewBelief1OrderRelTo(h,1);


    return 0;
}
