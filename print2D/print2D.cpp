#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    cout << "|Row |" << setfill(' ')
    << "A" << setw(1) << setw(2) << '|' << setw(1) 
    << "B" << setw(2) << '|';
}