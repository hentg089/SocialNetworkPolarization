#include <iostream>
#include "Model.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Model p(3,2,4);
    std::string temp = "";
    int z = 2;
    p.calculateOrderBeliefs(z,1,temp);

    return 0;
}
