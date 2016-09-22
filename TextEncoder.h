//
// Created by nantus on 05.09.16.
//

#ifndef SOLVER_TEXTENCODER_H
#define SOLVER_TEXTENCODER_H

#include <string>
#include <vector>
#include "DTree.h"

class cTextEncoder{
public:
    cTextEncoder();
    ~cTextEncoder();

    void Encode(std::string Formula);

    double getValue(double varValue);
private:
    std::vector<char> variables;
    DTree* myTree;
};

#endif //SOLVER_TEXTENCODER_H
