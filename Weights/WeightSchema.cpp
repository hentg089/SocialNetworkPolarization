//
// Created by markh on 3/9/2024.
//

#include "WeightSchema.h"
#include <cmath>

WeightSchema::WeightSchema(int weightCount, double a, double r) {
    this->weightCount = weightCount;
    this->a = a;
    this->r = r;
}

double WeightSchema::getIthWeight(int index) {
    if(index == 1){
        return a;
    }
    //if n is ven then we are dealing with higher order belief
    if(weightCount % 2 == 0){
        if(index == 2){
            return a * r;
        }
        int temp = (index - 2)/2;
        if (index > 2 + temp){
            index -= temp;
        }

        return a * pow(r, index - 1);

    }else{

    }
}