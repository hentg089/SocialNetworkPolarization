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

    //if n is ven then we are dealing with higher order belief
    if(weightCount % 2 == 0){
        int temp = (weightCount - 2)/2;
        if (index > 2 + temp){
            index -= temp;
        }
        double ans = a * pow(r, index - 1);
        if (index > 2){
            ans /= 2;
        }

        if(index == 2 + temp){
            double add = pow(r, index);
            if(index > 2){
                add /= 2;
            }
            ans += add;
        }
        return ans;
    }else{
        int temp = (weightCount - 1)/2;
        if(index > 1 + temp){
            index -= temp;
        }
        double ans = a * pow(r, index-1);
        if(index > 1){
            ans /= 2;
        }

        if(index == 1 + temp){
            double add = pow(r, index);
            if(index > 1){
                add /= 2;
            }
            ans += add;
        }
        return ans;
    }
}