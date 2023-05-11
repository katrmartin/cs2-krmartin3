
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, i, p, temp;
    vector <int> seeds;
    cin >> N;
    
    for (int j = 0; j < N; j++) {
        cin >> i;
        seeds.push_back(i);
    }

    //sort(seeds.begin(), seeds.end(), greater<int>()); 

    bool done = false;
    while (!done) {
        done = true;
        temp = seeds[0];
            for (p = 1; p < seeds.size(); p++) {
                if (seeds[p] == temp) {
                    seeds[p-1]++;   
                    done = false;
                }
                else temp = seeds[p];
                    
            } 

    }


    //make sure no numbers are the same, increment by 1 if they are until all numbers are different #FIXED
    //add 2 to the biggest number #FIXED

    cout << seeds[0] + 2 << endl;


    return 0;
}
