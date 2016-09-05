//
// Created by nantus on 04.09.16.
//

#include "Euler1.h"
#include "CError.h"

Euler1::Euler1(){
    eps  = 1e-7;
    hMin = 1e-6;
    hMax = 100000;
    updateStep();
}

void Euler1::updateStep() {
    h = sqrt(hMin*hMax);
}

void Euler1::setStep(double newStep) {
    if(!newStep || newStep < hMin || newStep > hMax)
        throw CError("Bad step value!");

    h = newStep;
}

//For vector:
void Euler1::Solve(double _y0, double _x0, std::vector<double> mTime, double (*function)(double, double)) {
    solution.push_back(_y0);

    for(int i(0);i < mTime.size();i++) {
        if((mTime.size()-i) != 1)
            setStep(mTime[i+1]-mTime[i]);
        solution.push_back(solution[i] + h * function(mTime[i], solution[i]));
    }

    solution.erase(solution.end()-1);
}

//For time bordered by user:
void Euler1::Solve(double _y0, double _t0, double endTime, double (*function)(double, double)) {
    int count = 0;
    solution.push_back(_y0);

    for(double i(_t0);i<=endTime;i+=h){
        solution.push_back(solution[count] + h*function(i,solution[count]));
        count++;
    }
    //kostil`
    solution.erase(solution.end()-1);
}

std::vector<double> Euler1::getSolution() {
    if(solution.empty())
        return std::vector<double>();

    return solution;
}

