//
// Created by nantus on 11.09.16.
//

#ifndef SOLVER_DTREE_H
#define SOLVER_DTREE_H

#include "mainConstants.h"

template <typename myType>
class DTree{
    struct Node{
        myType data;
        int keyDataType;
        Node* Parent;
        Node* Left;
        Node* Right;
    };

    void add(int keyDataType,myType data,Node** node){
        if(*node == nullptr){
            *node = new Node;
            (*node)->data        = data;
            (*node)->keyDataType = keyDataType;
        }
        else
        if(   (*node)->Left == nullptr
           || (*node)->Left->keyDataType == compilerDataTypes::operator_)
            add(keyDataType,data,&(*node)->Left);
        else
        if((*node)->Left != nullptr && (*node)->Right == nullptr)
            add(keyDataType,data,&(*node)->Right);
        else
        if(   ((*node)->Left->keyDataType == compilerDataTypes::constant
           ||  (*node)->Left->keyDataType == compilerDataTypes::variable)
           && ((*node)->Right->keyDataType != compilerDataTypes::constant
           ||  (*node)->Right->keyDataType != compilerDataTypes::variable))
            add(keyDataType,data,&(*node)->Right);
    }

    myType toMyType(myType value){}

    myType canculate(myType keyDataType, myType num1, myType num2){
        switch(keyDataType){
            case compilerDataTypes::operator_Plus:
                return num1 + num2;

            case compilerDataTypes::operator_Minus:
                return num1 - num2;

            case compilerDataTypes::operator_Multiple:
                return num1 * num2;

            case compilerDataTypes::operator_Division:
                if(num2 != 0)
                    return num1 / num2;
        }
    }

    void compile(Node** node, std::vector<std::tuple<char,myType> >* variables){
        if(    (*node)->keyDataType == compilerDataTypes::operator_
           && ((*node)->Left->keyDataType == compilerDataTypes::constant
           ||  (*node)->Left->keyDataType == compilerDataTypes::variable)
           && ((*node)->Right->keyDataType == compilerDataTypes::constant
           ||  (*node)->Right->keyDataType == compilerDataTypes::variable)) {
            (*node)->keyDataType = compilerDataTypes ::constant;
            (*node)->data = conculate((*node)->data,(*node)->Left->data,(*node)->Right->data);
        }
        else
            compile(&(*node)->Left, variables);
    }

    Node* Root;

    myType mValue;
public:
    DTree(){
        Root   = nullptr;
        mValue = 0;
    }

    void Add(int keyDataType,myType data){
        add(keyDataType,data,&Root);
    }

    void Compile(std::vector<std::tuple<char,myType> >* variables){
        compile(&Root,variables);
    }
};

#endif //SOLVER_DTREE_H
