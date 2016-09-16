
#include "DTree.h"

DTree::DTree(){
    Root   = nullptr;
    mValue = 0;
}

void DTree::Add(int keyDataType,double data){
    add(keyDataType,data,&Root);
}

void DTree::Compile(std::vector<std::tuple<char,double> >* variables){
	compile(&Root,variables);
}

void DTree::add(int keyDataType,double data,Node** node){
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

double DTree::calculate(int keyDataType, double num1, double num2){
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

void DTree::compile(Node** node, std::vector<std::tuple<char,double> >* variables){
        if(    (*node)->keyDataType == compilerDataTypes::operator_
           && ((*node)->Left->keyDataType == compilerDataTypes::constant
           ||  (*node)->Left->keyDataType == compilerDataTypes::variable)
           && ((*node)->Right->keyDataType == compilerDataTypes::constant
           ||  (*node)->Right->keyDataType == compilerDataTypes::variable)) {
            (*node)->keyDataType = compilerDataTypes ::constant;
            (*node)->data = calculate((*node)->data,(*node)->Left->data,(*node)->Right->data);
        }
        else
            compile(&(*node)->Left, variables);
    }
	