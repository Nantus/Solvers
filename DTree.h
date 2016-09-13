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

    Node* Root;
public:
    DTree(){
        Root = nullptr;
    }

    void Add(int keyDataType,myType data){
        add(keyDataType,data,&Root);
    }
};

#endif //SOLVER_DTREE_H
