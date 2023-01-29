#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

int playerNum, solved;
vector <string> descriptions;

cin >> playerNum >> solved;

//cout << playerNum << ' ' << solved << endl;

for (int i = 0; i < playerNum; i++) {
    string desc;
    cin >> desc;
    descriptions.push_back(desc);
}

cout << solved << endl;


    return 0;
}