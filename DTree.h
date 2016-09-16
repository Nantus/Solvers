
#ifndef SOLVER_DTREE_H
#define SOLVER_DTREE_H

#include "mainConstants.h"
#include <vector>
#include <tuple>

class DTree{
    struct Node{
        double data;
        int keyDataType;
        Node* Parent;
        Node* Left;
        Node* Right;
    };

    void add(int keyDataType,double data,Node** node);
       
    double toMyType(double value);

    double calculate(int keyDataType, double num1, double num2);

    void compile(Node** node, std::vector<std::tuple<char,double> >* variables);

    Node* Root;

    double mValue;
public:
    DTree();      
	
	~DTree();
		
    void Add(int keyDataType,double data);

    void Compile(std::vector<std::tuple<char,double> >* variables);
};

#endif //SOLVER_DTREE_H