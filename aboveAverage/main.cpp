#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector <float> stats;
    int C;
    cin >> C;
    for (int j = 0; j < C; j++) {
        int N;
        int sum = 0;
        float average = 0;
        cin >> N;
        vector <float> dataLine;
        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            dataLine.push_back(data);

        }
        for (int k = 0; k < dataLine.size(); k++) {
            sum += dataLine[k];
        }

        average = sum/N;
        int aboveAverageCounter = 0;
        
        for (int p = 0; p < N; p++) {
            if (dataLine[p] > average)
            aboveAverageCounter++;
        }
        float aboveAverage = 0;
        aboveAverage = (aboveAverageCounter/N) * 100;
        stats.push_back(aboveAverage);

        
        //how to compare student grades with average

        dataLine.clear();

    
    }

    for (int t = 0; t < C; t++) {
        cout << setprecision(3);
        cout << stats[t] << "%" << endl;
    }

    /*

    */
    



    return 0;
}