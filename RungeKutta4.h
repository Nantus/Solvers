//
// Created by nantus on 04.09.16.
//

#ifndef SOLVER_RUNGEKUTTA4_H
#define SOLVER_RUNGEKUTTA4_H

#include <vector>
#include <iostream>
#include <math.h>

class RungeKutta4{
public:
    RungeKutta4();

    void Solve(double _y0, double _t0, std::vector<double> intTime, double (*function)(double,double));
    void Solve(double _y0, double bord, double (*function)(double, double));
    void setStep(double newStep);
    std::vector<double> getSolution();
private:
    void updateStep();

    double K1;
    double K2;
    double K3;
    double K4;

    double hMax;
    double hMin;
    double h;

    std::vector<double> solution;
};

#endif //SOLVER_RUNGEKUTTA4_H
