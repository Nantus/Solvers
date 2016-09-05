//
// Created by nantus on 04.09.16.
//

#ifndef SOLVER_EULER1_H
#define SOLVER_EULER1_H

#include <vector>
#include <math.h>

class Euler1 {
public:
    Euler1();

    virtual void Solve(double _y0, double _t0, double endTime, double (*function)(double,double));
    virtual void Solve(double _y0,double _t0, std::vector<double> mTime, double (*function)(double,double));
    void setStep(double newStep);
    void setEps(double  newEps);
    std::vector<double> getSolution();

private:
    void updateStep();

    double hMin;
    double hMax;
    double h;
    double eps;

    std::vector<double> solution;
};


#endif //SOLVER_EULER1_H
