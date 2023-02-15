//stack notes from 2/13

#include <iostream>

using namespace std;

//stack = last in first out
//queue = first in first out

/* 0
 * 1
 * . . .
 * 98
 * 99  <- Position starting point
 * */

class StackException {
    public:
    void print() {
        cerr << "Stack Exception Occurred" << endl;
    }
};

const int MAXSTACK=100;
template <typename t> class Stack {
    t values[MAXSTACK];
    int position;
    public:
    Stack() { position = MAXSTACK - 1; }
    void push(t newValue) {
        if (!isFull()) {
            values[position] = newValue;
            position--;
        }
        else throw StackException(); //what does throw mean?
        
    }
    t pop() {
        if (!isEmpty()) {
            position++;
            return values[position];
        }
        //return t(); we shouldn't do this
        throw StackException();
    }
    t top() {
        if (!isEmpty()) return values[position+1];
        //return t(); we shouldn't do this
        throw StackException();
    }
    bool isEmpty() { return (position == MAXSTACK - 1); }
    // same as if (position == MAXSTACK - 1) return true; else return false;
    bool isFull() { return (position == -1); }

};


int main() {
    Stack<int> s;
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