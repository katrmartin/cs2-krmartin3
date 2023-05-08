#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

/*
abstract:
I'm going to make a time management calendar software where you give the program a
file with information, and it outputs an organized, helpful version in calendar form.  I want to 
make a weekly calendar that has the days, dates, and information about what you spend your 
time on.  Then the helpful part would be that it tells you how you distributed your time that 
week.  I’ll add silly phrases that are rude to you if you exceed a threshold of time on something 
like phone time or you don’t get enough sleep.  Essentially, the program takes lines of text from 
an input file, formats it, calculates some statistics, and spits out a formatted calendar version with 
some snarky comments.
*/

class eachDay {
private:
    int month, day;
    double sleep;
    double phone;
    double school;
    double social;
    double work;
    string mood;
    string fileName;
    public:
//get, set functions

    eachDay (double newSleep=0.0, double newPhone=0.0, double newSchool=0.0, 
        double newSocial=0.0, double newFileName=0.0, double newWork=0.0,
         string newMood="") {
            sleep = newSleep;
            phone = newPhone;
            school = newSchool;
            social = newSocial;
            fileName = newFileName;
            work = newWork;
            mood = newMood;
        }
        
    void setFile (string newFileName) {
        fileName = newFileName;
    }
    string getFile () {
        return fileName;
    }
    void readFile (ifstream &fin) {
            fin.open(fileName);
            getline(fin, mood);
            //configure to ignore first 2 numbers
            fin >> month >> day;
            fin >> sleep >> phone >> school >> social
            >> work;
            //need to make sure it only reads in what I need
            fin.close(); //might be better as its own function
    }
    string getDate () {
        return month + " " + day;
    }
    string getMood() {
        return mood;
    }
    double getSleep () {
        return sleep;
    }
    double getPhone () {
        return phone;
    }
    double getSchool () {
        return school;
    }
    double getSocial () {
        return social;
    }
    double getWork () {
        return work;
    }
    double sleepDist() {
        return 168/sleep;
    }
    double phoneDist() {
        return 168/phone;
    }
    double schoolDist() {
        return 168/school;
    }
    double socialDist() {
        return 168/social;
    }
    double workDist() {
        return 168/work;
    }

};

enum DAYOFWEEK {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

class Week: public eachDay {
protected:
    vector <eachDay> days;
    //days[MONDAY].getFromUser()

public:
    void compileDays (vector <eachDay> days) {
        //put all days into week vector
    }
    void readWeek (ifstream &fin) {
        for (int i = 0; i < 7; i++) {
            eachDay data;
            data.readFile(fin);
            days.push_back(data);      
        }
        
    }

    double sleepDistWeek(eachDay &data) {
        double total = 0;
        for (int i = 0; i < 7; i++) {
            total += days[i].getSleep();
        }
        return 168/total;
    }
    double phoneDistWeek(eachDay &data) {
        double total = 0;
        for (int i = 0; i < 7; i++) {
            total += days[i].getPhone();
        }
        return 168/total;
    }
    double schoolDistWeek(eachDay &data) {
        double total = 0;
        for (int i = 0; i < 7; i++) {
            total += days[i].getSchool();
        }
        return 168/total;
    }
    double socialDistWeek(eachDay &data) {
        double total = 0;
        for (int i = 0; i < 7; i++) {
            total += days[i].getSocial();
        }
        return 168/total;
    }
    double workDistWeek(eachDay &data) {
        double total = 0;
        for (int i = 0; i < 7; i++) {
            total += days[i].getWork();
        }
        return 168/total;
    }
};

class Calendar: public Week {
public:

    void calendarFormatter (ofstream &fout) {
        fout << "MONDAY" << endl;
        fout << "--------" << endl;
        fout << days[MONDAY].getMood() << endl;
    }
    void outFile (eachDay &eachday, Week &week) {
        ofstream fout;
        fout.open("Calendar.txt");
        calendarFormatter(fout);
        //test
        
    }
    void readFeedbackFile() {
        ifstream fin;
        //if phone dist is some number then
        fin.open("PhoneJudge.txt");
        //randomly pick one of the lines to use
        //if sleep dist is some number then
        //fin.open("SleepJudge.txt")
        //etc

    }
};


int main () {
    cout << "Hello, welcome to the calendar that shows you" <<
    " how you spend your time in a week!" << endl;
    cout << endl;
    cout << "Please enter your file name: ";
    eachDay data;
    Week week;
    Calendar calendar;
    ifstream fin;
    ofstream fout;
    string name;
    getline(cin, name);
    data.setFile(name);
    week.readWeek(fin);
    calendar.outFile(data, week);




    return 0;
}

//other files will have comments that are randomly picked to add as "feedback"
//to the calendar based on time distribution results

