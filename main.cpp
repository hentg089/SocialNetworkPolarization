#include <iostream>
#include "Model.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Model p(10,2,4);
    std::string temp = "";
    int z = 2;
    p.calculateOrderBeliefs(z,3,temp);

    return 0;
}
