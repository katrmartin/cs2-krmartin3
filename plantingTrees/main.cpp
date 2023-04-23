/*
4
2 3 4 3

xxxx
xxx xxx
xx xx xxx
x x xx xx 
x x 
0 0
7 days

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, i, newSeeds;
    vector <int> seeds;

    cin >> N;
    
    for (int j = 0; j < N; j++) {
        cin >> i;
        seeds.push_back(i);
    }

    sort(seeds.begin(), seeds.end()); 

    for (auto c: seeds) {
        cout << c << " ";
    }
    cout << endl;

            for (int p = 0; p < seeds.size(); p++) {
                    newSeeds = seeds[p] + p;  

                    
            } 

6
9 20 35 38 39 39

9 + 0 = 9

2 3 4 3
XX
X XXX
XX XXX
X XXX XXXX
XX XXX 
X XX 
X 





    cout << newSeeds << endl;


    return 0;
}
