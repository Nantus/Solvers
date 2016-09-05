//
// Created by nantus on 04.09.16.
//

#include "CError.h"

CError::CError(std::string Case) : std::exception() {
    if(!Case.empty())
        whatHappened = Case;
    else
        whatHappened = "Unknown error!";
}

CError::CError() {
    whatHappened = "Unknown error!";
}

const char *CError::what() const throw(){
    return whatHappened.c_str();
}

