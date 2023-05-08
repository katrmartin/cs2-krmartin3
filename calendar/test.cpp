#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>

using namespace std;

class File {
    string fileName;
    public:
    void setFile(string newFileName) {
        fileName = newFileName;
    }
    string getFile () {
        return fileName;
    }
    void openFile(ifstream &fin) {
        fin.open(fileName);
    }
    void closeFile(ifstream &fout) {
        fout.close();
    }

};

class eachDay {
    protected:
    int month, day;
    string mood;
    double sleep, school, phone, social, work;
    public:
    void setMonth(int newMonth) {
        month = newMonth;
    }
    void setDay(int newDay) {
        day = newDay;
    }
    void setMood(string newMood) {
        mood = newMood;
    }
    void setSleep(double newSleep) {
        sleep = newSleep;
    }
    void setSchool(double newSchool) {
        school = newSchool;
    }
    void setPhone(double newPhone) {
        phone = newPhone;
    }
    void setSocial(double newSocial) {
        social = newSocial;
    }
    void readDay(File file, ifstream &fin) {
        file.openFile(fin);
        fin >> month >> day;
        getline(fin, mood);
        fin >> sleep >> school >> phone >> social;
        
    }
};

class Week: public eachDay {
    vector <eachDay> theWeek;

    void readWeek(File file, ifstream &fin) {
        for (int i = 0; i < 7; i++) {
            eachDay::readDay(file, fin);
            theWeek.push_back() //????
        }
    }
};

class Calendar: public Week {
    //format output for calendar
    //print onto file
    //file is named ex. Week of 4/30 - 5/7
    //perhaps put interactive menu here?
};

int main() {
    ifstream fin;
    ofstream fout;
    string fileName;
    string load = "Generating . . .";

    cout << "Enter file name: ";
    cin >> fileName;
    File file;
    file.setFile(fileName);

for (int i = 0; i < 3; i++) {
    for (auto ch: load) {
        cout << ch;
        usleep(1000);
    }
}
    Week week;

cout << endl;


    

    return 0;
}