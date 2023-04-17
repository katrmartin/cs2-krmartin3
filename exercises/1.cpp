#include <iostream>
#include <string>

using namespace std;

class Shape {
    public:
    int width=0, height=0;
    void setData (int newWidth, int newHeight) {
        width=newWidth;
        height=newHeight;
    }
};

class Triangle: public Shape {
    public:
    int area() {
      return (0.5*(width*height));  
    };
};

class Rectangle: public Shape {
    public:
    int area() {
      return width*height;  

    }
};

int main() {
    Triangle A;
    A.setData(3,4);
    Rectangle B;
    B.setData(3,4);
    cout << A.area() << endl;
    cout << B.area() << endl;
    return 0;
}