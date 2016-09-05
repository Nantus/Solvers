#include <iostream>
#include "Euler1.h"
#include "RungeKutta4.h"

double func(double _x,double _y){
    return _x*_x+_y+_y;//x^2+y^2
}

int main() {
    RungeKutta4 solver;

    std::vector<double> TimeVec;

    for(double i(0);i<=5;i+=0.1)
        TimeVec.push_back(i);

    solver.Solve(0,0,TimeVec,func);

    for(int i(0);i<solver.getSolution().size();i++)
        std::cout << solver.getSolution()[i] << std::endl;

    return 0;
}