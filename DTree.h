
#ifndef SOLVER_DTREE_H
#define SOLVER_DTREE_H

#include "mainConstants.h"
#include <vector>
#include <utility>
#include <string>

class DTree{
    struct valuesToCompile{
        double data;
        int keyDataType;
    };

    struct Node{
        valuesToCompile compileData;
        double data;
        int keyDataType;
        Node* Parent;
        Node* Left;
        Node* Right;
    };

    void add(int keyDataType,double data,Node** node);

    double calculate(int keyDataType, double num1, double num2);

    void compile(Node **node, std::vector<std::pair<char, double> > *variables);

    double varToDouble(std::vector<std::pair<char,double> > varList, double data);

    void updateCompiledData(Node** node);

    Node* Root;

    double mValue;
public:
    DTree();

    ~DTree();

    double getValue();

    void Add(int keyDataType,double data);

    void Compile(std::vector<std::pair<char, double> > *variables);
};

#endif //SOLVER_DTREE_H