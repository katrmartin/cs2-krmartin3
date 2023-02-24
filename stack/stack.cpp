
//stack notes from 2/13, 2/16

#include <iostream>
#include "stack.hpp"
#include "stack1.cpp"

using namespace std;

//stack = last in first out
//queue = first in first out

/* 0
 * 1
 * . . .
 * 98
 * 99  <- Position starting point
 * */


int main() {
    Stack s;
   // s.push(16);
   // s.push(20);
    // cout << s.pop() << endl;
    // cout << s.pop() << endl;

//old fashioned calculator
//cout << 5*(6+1) << endl = 5 6 1 + * !
//cout << 5*6+1 << endl = 5 6 * 1 + !

string input;
cin >> input;
try {
while (input!="!") {
        if (input[0]>='0' && input[0]<='9') { //if it's a number
            s.push(input[0]-'0');
        }
        else {
            if (input[0]=='+') {
                int a = s.pop();
                int b = s.pop();
                s.push(a+b);
            }
            if (input[0]=='*') {
                int a = s.pop();
                int b = s.pop();
                s.push(a*b); 
            }
        }
        cin >> input;
    }
        cout << s.top() << endl;
    }catch (StackException e) {
        e.print();
    }

    return 0;
    
}