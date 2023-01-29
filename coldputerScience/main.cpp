#include <iostream>
#include <vector>

using namespace std;

int main () {
    int num;
    vector <int> temps;
    int counter = 0;
    int singleTemp;

    cin >> num;

    for(int i = 0; i < num; i++) {
        cin >> singleTemp;
        temps.push_back(singleTemp);
    }


    for (int j = 0; j < temps.size(); j++) {
        if (temps[j] < 0)
            counter++;
    }

    cout << counter << endl;

    return 0;
}