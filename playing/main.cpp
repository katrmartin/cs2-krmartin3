#include <iostream>

using namespace std;

void fun (int &x) {
    x = x + 5;
}

int main() {
    int x = 5;
    fun(x);
    cout << x << endl;
}