//
// Created by nantus on 05.09.16.
//

#ifndef SOLVER_ALGORITHMITEM_H
#define SOLVER_ALGORITHMITEM_H

template <typename myType>
class cAlgorithmItem{
public:
    cAlgorithmItem(){}
    ~cAlgorithmItem(){}

    virtual myType getInfo() = 0;

    virtual void runItem() = 0;
private:
    cAlgorithmItem* next;
    myType myInfo;
};



#endif //SOLVER_ALGORITHMITEM_H
