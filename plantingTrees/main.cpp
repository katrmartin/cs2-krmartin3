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
    int N, i, p, temp;
    vector <int> seeds;

    cin >> N;
    
    for (int j = 0; j < N; j++) {
        cin >> i;
        seeds.push_back(i);
        //cout << "here" << endl;
        if (j > N) break;
    }
    //cout << "Here pls" << endl;

    //temp = seeds[0];
    sort(seeds.begin(), seeds.end());

    bool b = true;
    while (b == true) {
            for (p = 1; p < seeds.size(); p++) {
                if (seeds[p] == seeds[p-1])
                    seeds[p]++;   
                     
                
                if (seeds[p] != seeds[p])
                    b = false;
                else b = true;
            }
            
            

    }

    
    sort(seeds.begin(), seeds.end(), greater<int>()); 

    //make sure no numbers are the same, increment by 1 if they are until all numbers are different #FIXED
    //add 2 to the biggest number #FIXED

    /*for (auto c: seeds) {
        cout << c << " ";
    }
    */
    //test
    cout << endl;

    cout << seeds[0] + 2 << endl;





    return 0;
}
