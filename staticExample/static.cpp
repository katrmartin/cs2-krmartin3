// static keyword demonstration

#include <iostream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class A {
    static int count;
    string first, last;
    public:
    A(string newFirst, string newLast) {
        first=newFirst;
        last=newLast;
        count++;
    }
    static void outputLabels(ostream &out) {
        out << "First,Last" << endl;
    }
    void output(ostream &out) {
        out << first << ',' << last << ',' << count << endl;
    }
};
int A::count=0;

//recursive example
int fib(int n) {
    if (n<2) return 1;
    return (fib(n-1) + fib(n-2));
}

//recursive iterative (confusing)
int iterativeFib(int n) {
    queue<pair<int,int>> fibs;
    if (n>2)
    fibs.push_back(pair<int,int>(n-1,n-2));
    while (!fibs.empty()) {
        pair<int,int> p= fibs.front();
        fibs.pop();
        int total = 0;
        if (p.first<2) total+=1;
        else fibs.push_back(pair<int,int>(p.first-1,p.first-2));
        if (p.second<2) total+=1;
        else fibs.push_back(pair<int,int>(p.second-1,p.second-2));
    }

    if (n<2) return 1;
    return (fib(n-1) + fib(n-2));
}

int main() {
    //static example
    A karl("Karl, Castleton");
    A kim("Kim", "Castleton");
    A::outputLabels(cout);
    karl.output(cout);

    //recursive example
    cout << fib(10) << endl;
}