#include <iostream>
#include <cassert>

#ifndef STACK_HPP
#define STACK_HPP
//or...
//#pragma once
//protecting against multiple includes

using namespace std;

class StackException {
    public:
    void print();
};

const int MAXSTACK=100;
class Stack {
    double values[MAXSTACK];
    int position;
    public:
    Stack();
    void push(double);   
    double pop();
    double top(); 
    bool isEmpty(); 
    bool isFull();
};

#endif