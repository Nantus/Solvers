//
// Created by nantus on 05.09.16.
//

#ifndef SOLVER_TEXTENCODER_H
#define SOLVER_TEXTENCODER_H

#include <string>
#include "AlgorithmItem.h"

class cTextEncoder{
public:
    cTextEncoder();
    ~cTextEncoder();

    void Encode(std::string Formula);

private:
    cAlgorithmItem<double> myAlgorithm;
};

#endif //SOLVER_TEXTENCODER_H
