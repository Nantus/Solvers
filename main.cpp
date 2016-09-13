#include <iostream>
#include "Euler1.h"
#include "RungeKutta4.h"
#include "mainConstants.h"
#include "DTree.h"

double func(double _x,double _y){
    return _x*_x+_y+_y;//x^2+y^2
}

int main() {
    DTree<double> tree;
    tree.Add(compilerDataTypes::operator_,compilerDataTypes::operator_Plus);
    tree.Add(compilerDataTypes::constant,2);
    tree.Add(compilerDataTypes::constant,2);
    return 0;
}