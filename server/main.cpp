#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, T, x, sum = 0, completed = 0;
    vector <int> data;
    cin >> n >> T;

    for (int i = 0; i < n; i++) {
        cin >> x;
        data.push_back(x);
    }

    for (int j = 0; j <= T; j++) {
        sum += data[j];
        if (sum <= T) {
            completed++;
    
        }
        if (sum <= data[j-1])
            break;

        
        

    }

    cout << completed << endl;

    return 0;
}