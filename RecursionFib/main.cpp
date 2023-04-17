//formula for trapezoid -> A = ((a+b)/2)*h

#include <iostream>
#include <cmath>

using namespace std;

//1 1 2 3 5 8 13 21
int fib(int n) {
    if (n<=1) return 1;
    return fib(n-1)+fib(n-2);
}

double f(double x) {
    //return sin(x)*log(x)/sqrt(3*x);
    return log(x);
}
class Integrate{
    public:
    virtual double f(double x)=0;
double integrate(double a, double b, double epsilon=0.001) {
    double h=b-a;
    double ha=f(a);
    double hb=f(b);
    double m=(a+b)/2;
    double hm= f(m);

    double A2=((ha+hb)/2)*h; //2 point method
    double A3=((ha+hm)/2)*(h/2)+((hm+hb)/2)*(h/2); //3 point method
    if (fabs(A2-A3)<epsilon) {
        return A3;
    }
    else return integrate(a,m, epsilon/2)+integrate(m,b);
}
};
//abstract class ^^^
class IntegrateX: public Integrate{
    double f(double x) { return x; }
};
//concrete class ^^^

int main () {
    //for (int i = 0; i < 10; i++)
        //cout << fib(i) << endl;
        IntegrateX tool;
        double ans = tool.integrate(1, 2);
    //double ans = integrate(0.01,1);
    cout << ans << endl;
    return 0;
}