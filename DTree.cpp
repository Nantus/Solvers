
#include <iostream>
#include "DTree.h"

DTree::DTree(){
    Root   = nullptr;
    mValue = 0.0;
}

void DTree::Add(int keyDataType,double data){
    add(keyDataType,data,&Root);
}

void DTree::Compile(std::vector<std::pair<char, double> > *variables){
	compile(&Root,variables);
    mValue = Root->compileData.data;
    updateCompiledData(&Root);
}

void DTree::add(int keyDataType,double data,Node** node){
    if(*node == nullptr){
        *node = new Node;
        (*node)->data        = data;
        (*node)->keyDataType = keyDataType;
        (*node)->compileData.data = data;
        (*node)->compileData.keyDataType = keyDataType;
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

void DTree::compile(Node **node, std::vector<std::pair<char, double> > *variables){
    if((*node)->Left->keyDataType == compilerDataTypes::operator_)
        compile(&(*node)->Left, variables);

    if((*node)->Right->keyDataType == compilerDataTypes::operator_)
        compile(&(*node)->Right, variables);

    if(    (*node)->compileData.keyDataType == compilerDataTypes::operator_
           && ((*node)->Left->compileData.keyDataType == compilerDataTypes::constant
           ||  (*node)->Left->compileData.keyDataType == compilerDataTypes::variable)
           && ((*node)->Right->compileData.keyDataType == compilerDataTypes::constant
           ||  (*node)->Right->compileData.keyDataType == compilerDataTypes::variable)) {
            (*node)->compileData.keyDataType = compilerDataTypes ::constant;
        double dFirstOperand  = varToDouble(*variables,(*node)->Left->compileData.data);
        double dSecondOperand = varToDouble(*variables,(*node)->Right->compileData.data);
        int dataType          = static_cast<int>((*node)->data);
        (*node)->compileData.data = calculate(dataType, dFirstOperand, dSecondOperand);
    }

}

double DTree::varToDouble(std::vector<std::pair<char, double> > varList, double data) {
    int var = static_cast<int>(data);

    for(int i(0);i < varList.size();i++)
        if(var == varList[i].first)
            return varList[i].second;

    return data;
}

DTree::~DTree() {

}

double DTree::getValue() {
    return mValue;
}

void DTree::updateCompiledData(Node** node) {
        (*node)->compileData.keyDataType = (*node)->keyDataType;
        (*node)->compileData.data        = (*node)->data;

    if(   (*node)->Left != nullptr
       && (*node)->Left->compileData.keyDataType != (*node)->Left->keyDataType)
        updateCompiledData(&(*node)->Left);
    else
    if(   (*node)->Right != nullptr
       && (*node)->Right->compileData.keyDataType != (*node)->Right->keyDataType)
        updateCompiledData(&(*node)->Right);
}
	