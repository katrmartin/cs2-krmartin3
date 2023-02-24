#include <iostream>
#include <cassert>
#include "stack.hpp"

//or...
//#pragma once
//protecting against multiple includes

using namespace std;


    void StackException::print() {
        cerr << "Stack Exception Occurred" << endl;
    }


    double values[MAXSTACK];
    int position;
    Stack::Stack() { position = MAXSTACK - 1; }
    void Stack::push(double newValue) {
        if (!isFull()) {
            values[position] = newValue;
            position--;
        }
        else throw StackException(); //what does throw mean?
        
    }
    double Stack::pop() {
        if (!isEmpty()) {
            position++;
            return values[position];
        }
        //return t(); we shouldn't do this
        throw StackException();
    }
    double Stack::top() {
        if (!isEmpty()) return values[position+1];
        //return t(); we shouldn't do this
        throw StackException();
    }
    bool Stack::isEmpty() { return (position == MAXSTACK - 1); }
    // same as if (position == MAXSTACK - 1) return true; else return false;
    bool Stack::isFull() { return (position == -1); }
