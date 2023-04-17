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

            for (int p = 0; p < seeds.size(); p++) {
                    newSeeds = seeds[p] + p;  

                    
            } 


/*
    for (auto c: seeds) {
        cout << c << " ";
    }
    cout << endl;
*/


    //make sure no numbers are the same, increment by 1 if they are until all numbers are different #FIXED
    //add 2 to the biggest number #FIXED

    cout << newSeeds << endl;


    return 0;
}

/*
  bool done = false;
    while (!done) {
        done = true;
        temp = seeds[0];
            for (p = 1; p < seeds.size(); p++) {
                if (seeds[p] == temp) {
                    seeds[p] + p;   
                    done = false;
                    break;
                }
                else temp = seeds[p];
                    
            } 

    }
*/
