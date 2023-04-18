#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int lines;
    vector<string>sentences;
    string sentence;
    string keyword= "simon says ";

    cin >> lines;
    cin.ignore();

    for (int i = 0; i < lines; i++) {
        getline(cin, sentence);
        sentences.push_back(sentence);
    }

    for (int j = 0; j < sentences.size(); j++) {
        string phrase = sentences[j];
        if (phrase.find(keyword) == 0)
            cout << phrase.substr(11) << endl;
        else {
            cout << endl;
        }
    }

    return 0;
}