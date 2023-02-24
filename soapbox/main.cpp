
//soapbox notes from 2/20/23

#include <iostream> //to use the library iostream cout cin

using namespace std; //so that we don't have to say std:: every 5 seconds

Class A { //creates new type called A
    int x; //attribute of the class along with y
    float y;
    public: //other functions and main can use the stuff within public
    A () { //constructor function, has same name as class
        x = 0;
    }
    
    //next 3 functions are a transformation of fun()
    void fun() {
        cout << x << endl;
    }

    ostream & output(ostream & out) { //member function or method of class A
        cout << x << endl;
    }
    //explore this more what does it do?
    //ostream for writing friend functions

    friend ostream & operator <<(ostream &out, const A &other) {
        out << other.x << endl;
    }
    //friend allows us to easily overload operators like <<
    //study this pointers and friend relationship

};

Class B: public A {
//A is the superclass of B
//B is the subclass and derived from A

};

//can't do const & for fun() because we attempt to change x within the function

int fun(int y, int &x) {
    y+=3;
    x+=2;
    return x+y;
}

int main() {
  try {   
    int x = 0;
    int y = 0;
    y = fun(x, y);
    if (y==5) throw A();
    cout << x << " " << y << endl;
  } catch (A &a) {
    cout << a << endl;
   }

    return 0;
}

//try, catch, and throw keywords to study
//study stack code
//study ostream, friend, and this pointers