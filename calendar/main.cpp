#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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
/*
    eachDay (double newSleep, double newPhone, double newSchool, 
        double newSocial, double newFileName, double newWork,
         string newMood) {
            sleep = newSleep;
            phone = newPhone;
            school = newSchool;
            social = newSocial;
            fileName = newFileName;
            work = newWork;
            mood = newMood;
        }
        */
    void setFile (string newFileName) {
        fileName = newFileName;
    }
    string getFile () {
        return fileName;
    }
    void readFile () {
            ifstream fin;
            fin.open(fileName);
            getline(fin, mood);
            //configure to ignore first 2 numbers
            fin >> month >> day;
            fin >> sleep >> phone >> school >> social
            >> work;
            //need to make sure it only reads in what I need
            //fin.close(); //might be better as its own function
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


/*
getFromUser() to gather user input from file or iostream
    double m_sleepDist; //distribution of time throughout week spent on sleep
    double m_phoneDist; //not needed as member variable
    double m_schoolDist;
    double m_socialDist;
*/

};

enum DAYOFWEEK {MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

class Week {
private:
    vector <eachDay> days;
    //days[MONDAY].getFromUser()

public:
//functions
    void compileDays (vector <eachDay> days) {
        //put all days into week vector
    }
    void readWeek () {
        for (int i = 0; i < 7; i++) {
            eachDay data;
            data.readFile();
            days.push_back(data);      
        }
        

    }
    void getSun () {
        cout << days[0].getDate() << endl;
        cout << days[0].getMood() << endl;
        cout << days[0].getSleep() << endl;
        cout << days[0].getSocial() << endl;
        cout << days[0].getPhone() << endl;
        cout << days[0].getWork() << endl;
        cout << days[0].getSchool() << endl;
    }
    void getMon () {
        cout << days[1].getDate() << endl;
        cout << days[1].getMood() << endl;
        cout << days[1].getSleep() << endl;
        cout << days[1].getSocial() << endl;
        cout << days[1].getPhone() << endl;
        cout << days[1].getWork() << endl;
        cout << days[1].getSchool() << endl;
    }
    void getTues () {
        cout << days[2].getDate() << endl;
        cout << days[2].getMood() << endl;
        cout << days[2].getSleep() << endl;
        cout << days[2].getSocial() << endl;
        cout << days[2].getPhone() << endl;
        cout << days[2].getWork() << endl;
        cout << days[2].getSchool() << endl;
    }
    void getWed () {
        cout << days[3].getDate() << endl;
        cout << days[3].getMood() << endl;
        cout << days[3].getSleep() << endl;
        cout << days[3].getSocial() << endl;
        cout << days[3].getPhone() << endl;
        cout << days[3].getWork() << endl;
        cout << days[3].getSchool() << endl;
    }
    void getThurs () {
        cout << days[4].getDate() << endl;
        cout << days[4].getMood() << endl;
        cout << days[4].getSleep() << endl;
        cout << days[4].getSocial() << endl;
        cout << days[4].getPhone() << endl;
        cout << days[4].getWork() << endl;
        cout << days[4].getSchool() << endl;
    }
    void getFri () {
        cout << days[5].getDate() << endl;
        cout << days[5].getMood() << endl;
        cout << days[5].getSleep() << endl;
        cout << days[5].getSocial() << endl;
        cout << days[5].getPhone() << endl;
        cout << days[5].getWork() << endl;
        cout << days[5].getSchool() << endl;
    }
    void getSat () {
        cout << days[6].getDate() << endl;
        cout << days[6].getMood() << endl;
        cout << days[6].getSleep() << endl;
        cout << days[6].getSocial() << endl;
        cout << days[6].getPhone() << endl;
        cout << days[6].getWork() << endl;
        cout << days[6].getSchool() << endl;
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

class Calendar {
public:

    void calendarFormatter () {
        //TBD
    }
    void outFile (eachDay eachday, Week week) {
        ofstream fout;
        fout.open("Calendar.txt");
        fout << "MONDAY: " << endl;
        week.getMonday();
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

    return 0;
}

//other files will have comments that are randomly picked to add as "feedback"
//to the calendar based on time distribution results

