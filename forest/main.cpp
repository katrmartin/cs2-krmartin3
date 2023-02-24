/*
3 = 4 3 2
1 = 2 3
2 = 2 4
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

map <int, vector<int> > myMap;

void ComparisonFinder3000 (map <int, vector<int> >);

void ComparisonFinder3000 (map <int, vector<int> > &M, int opinionCounter) {
        opinionCounter = myMap.size();
        cout << opinionCounter << endl; //correct
        for (int k = 0; k < 10000; k++) {
            if (myMap[k] == myMap[k+1]) opinionCounter--;

    //opinion = 0
    //2 2 example
    //person 1 opinion++
    //person 2 opinion++
    //if person 1 has same pairs as person 2 opinion--
    //give each person an opinion, then compare all people together to
    //subtract opinions
}
    cout << opinionCounter << endl;

}


int main () {
    int opinionCounter = 0;
    int T, P, person, tree;
    string line;

    cin >> P >> T;

    while (cin >> person >> tree) {
        myMap[person].push_back(tree);
        //make it stop after user presses enter and has no more input
    }

//debugging
/*
    for (auto pair: myMap) {
        int key = pair.first;
        cout << key << " KEY" << endl;
        for (int t : myMap[key]) {
            cout << t << " ";
            cout << endl;
            }
        }

    cout << endl;
    */

    ComparisonFinder3000(myMap, opinionCounter);
    
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