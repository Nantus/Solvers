//
// Created by nantus on 04.09.16.
//

#include "RungeKutta4.h"
#include "CError.h"

RungeKutta4::RungeKutta4() {
    hMax = 100000;
    hMin = 1e-6;
    updateStep();
}

void RungeKutta4::Solve(double _y0, double bord, double (*function)(double, double)) {
    solution.push_back(_y0);

    int j(0);
    for(double i(0);i<bord;i += h){
        K1 = function(i,solution[j]);
        K2 = function(i + h/2,solution[j] + (h*K1)/2);
        K3 = function(i + h/2,solution[j] + (h*K2)/2);
        K4 = function(i + h,  solution[j] +  h*K3);

        solution.push_back(solution[j] + h/6*(K1 + 2*K2 + 2*K3 + K4));
        j++;
    }

    solution.erase(solution.end()-1);
}

void RungeKutta4::Solve(double _y0, double _t0, std::vector<double> intTime, double (*function)(double, double)) {
    solution.push_back(_y0);

    for(int i(0);i<intTime.size();i++){
        if((intTime.size()-i) != 1)
            setStep(intTime[i+1]-intTime[i]);

        K1 = function(intTime[i],solution[i]);
        K2 = function(intTime[i] + h/2,solution[i] + (h*K1)/2);
        K3 = function(intTime[i] + h/2,solution[i] + (h*K2)/2);
        K4 = function(intTime[i] + h,  solution[i] +  h*K3);

        solution.push_back(solution[i] + h/6*(K1 + 2*K2 + 2*K3 + K4));
    }

    solution.erase(solution.end()-1);
}

void  RungeKutta4::updateStep() {
    h = sqrt(hMax*hMin);
}

std::vector<double> RungeKutta4::getSolution(){
    return solution;
}

void RungeKutta4::setStep(double newStep) {
    if(newStep == 0)
        throw CError("Bad step value!");

    h = newStep;
}
