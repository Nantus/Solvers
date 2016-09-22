//
// Created by nantus on 05.09.16.
//

#include <stack>
#include "TextEncoder.h"

cTextEncoder::cTextEncoder() {
    myTree = new DTree;

    variables.resize(1);
    variables[0] = 'x';
}

cTextEncoder::~cTextEncoder() {
    delete myTree;
}

void cTextEncoder::Encode(std::string Formula) {

}

double cTextEncoder::getValue(double varValue) {
    std::vector<std::pair<char, double> > vars;

    vars.resize(1);
    vars[0].first = variables[0];
    vars[1].second = varValue;
    myTree->Compile(&vars);

    return myTree->getValue();
}
