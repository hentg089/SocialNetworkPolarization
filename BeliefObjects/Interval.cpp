//
// Created by markh on 2/20/2024.
//

#include "Interval.h"

Interval::Interval() {
    l = 0;
    r = 1;
}

Interval::Interval(double l, double r)
    : r(r), l(l){

}

double Interval::getL() {
    return l;
}

double Interval::getR() {
    return r;
}

void Interval::setL(double l) {
    this->l = l;
}

void Interval::setR(double r) {
    this->r = r;
}

double Interval::center() {
    return (l + r) / 2;
}

double Interval::length() {
    return r - l;
}

