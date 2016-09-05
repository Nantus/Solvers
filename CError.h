//
// Created by nantus on 04.09.16.
//

#ifndef SOLVER_CERROR_H
#define SOLVER_CERROR_H

#include <string>
#include <exception>

class CError : public std::exception{
public:
    CError(std::string Case);
    CError();

    virtual const char* what() const throw();
private:
    std::string whatHappened;
};

#endif //SOLVER_CERROR_H
