#include <iostream>
#include "Euler1.h"
#include "RungeKutta4.h"
#include "mainConstants.h"
#include "DTree.h"

double func(double _x,double _y){
    return _x*_x+_y+_y;//x^2+y^2
}

int main() {
    DTree tree;

    tree.Add(compilerDataTypes::operator_,compilerDataTypes::operator_Plus);
    tree.Add(compilerDataTypes::variable, static_cast<double>('b'));
    tree.Add(compilerDataTypes::operator_,compilerDataTypes::operator_Multiple);
    tree.Add(compilerDataTypes::variable, static_cast<double>('a'));
    tree.Add(compilerDataTypes::operator_,compilerDataTypes::operator_Plus);
    tree.Add(compilerDataTypes::constant,2);
    tree.Add(compilerDataTypes::constant,1);

    std::vector<std::pair<char,double>> vars;
    vars.resize(2);
    vars[0].first = 'a';
    vars[0].second = 2;
    vars[1].first = 'b';
    vars[1].second = 16;

    tree.Compile(&vars);
    std::cout << tree.getValue();

    return 0;
}