#include <iostream>
#include <vector>
using namespace std;

vector<int> findFactors(int a) {
    vector<int> output;
    for (int i = 1; i<=a; i++) {
        if (a%i == 0)
            output.push_back(i);
    }
    return output;
}

int main() {
    int V;
    int cost = 2147483647;
    int x, y, z;
    cin >> V;
    vector<int> factors = findFactors(V);
        for(int f: factors) {
            x = f;
                for (int f2: factors) {
                    y = f2;
                        for (int f3: factors) {
                            z = f3;
                            if (V == x*y*z) {
                                int SA = 2*(x*y + x*z + y*z);
                                if (SA < cost)
                                    cost = SA;
                            }

                        }
                }
        }
        cout << cost << endl;


    
    return 0;
}


//SA = 2(lw + wh + lh)
//factors of the value
//compare l:w:h surface area until you get smallest cost
//have an initial cost variable set to the highest int value possible
//after each loop, compare the new SA with the cost, if SA is smaller, set cost equal to SA
//this will find the smallest value

