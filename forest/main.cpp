/*
1 = 2 3
2 = 2 4
3 = 3 2
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

map <int, vector<int> > myMap;

void ComparisonFinder3000 (map <int, vector<int> > &M, int P) {
    vector <int> folks;
    int opinions = 0;
    for (int l = 0; l < P; l++) {
        folks.push_back(l+1);
    }

    for (int i = 0; i < folks.size(); i++) {
        for (int j = i + 1; j < folks.size(); j++) {
            //cout << i << " " << j << endl;
            if (M[folks[i]] == M[folks[j]])
            {
                
                folks.erase(folks.begin()+(j));
                j--;
            }
        }
        opinions++;

    }

    cout << opinions << endl;
}

void SortingMachine3000 (map <int, vector<int> > &M) {
        for (auto& i: M) {
        sort(i.second.begin(), i.second.end());
            }
        }
      



int main () {
    //int opinionCounter = 0;
    int T, P, person, tree;
    string line;

    cin >> P >> T;

    while (cin >> person >> tree) {
        myMap[person].push_back(tree);
    }
//debugging

    SortingMachine3000(myMap);

        // for (auto pair: myMap) {
        // int key = pair.first;
        // cout << key << " KEY" << endl;
        // for (int t : myMap[key]) {
        //     cout << t << " ";
        //     cout << endl;
        //     }
        // }

    ComparisonFinder3000(myMap, P);
    
    return 0;
    }

/*
        if (cin.get() == '\n')
            break;

    
    for (int i = 0; i < T*P; i++) {
        cin >> person >> tree;
        myMap[person].push_back(tree);
        if (line.empty()) {
            break;          
        }
*/