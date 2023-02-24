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

class Calendar {
    //maybe eachDay should be a superclass?
private:
    int day;
    int month;
    eachDay day;

public:
    //get, set, formatting functions
    Calendar (int newMonth, int newDay) {
        day = newDay;
        month = newMonth;
    }
    void fileReadDate (eachDay day) {
        string fileName = day.getFile();
        ifstream fin;
        fin.open(fileName);
        fin >> month >> day;
        fin.close();
    }
    void calendarFormatter () {
        //TBD
    }
    void outFile () {
        //put formatted data into new file
    }
    void readFeedbackFile() {
        ifstream fin;
        //if phone dist is some number then
        fin.open("PhoneJudge.txt")
        //randomly pick one of the lines to use
        //if sleep dist is some number then
        //fin.open("SleepJudge.txt")
        //etc

    }
};

class eachDay {
private:
    double sleep;
    double phone;
    double school;
    double social;
    double work;
    string mood;
    string fileName;
    public:
//get, set functions
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
    void setFile (string newFileName) {
        fileName = newFileName;
    }
    string getFile () {
        return fileName;
    }
    void readFile (istream & fin) {
            //ifstream fin;
            //fin.open(fileName);
            //setFile(fileName);
            getline(fin, mood);
            //configure to ignore first 2 numbers
            fin >> sleep >> phone >> school >> social
            >> work;
            //need to make sure it only reads in what I need
            //fin.close(); //might be better as its own function
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
    void read (istream & fin) {
        for (int i = 0; i < 7; i++) {
            eachDay data;
            data.readFile(fin);
            days.push_back[data];
        }

    }
    void readFile(string fileName) {
            ifstream fin;
            fin.open(fileName);
            read(fin);
            fin.close();
        
    }

    double sleepDist (eachDay &data) {
        double sleeping = data.getSleep();
        //return percent time was spent
        //on sleeping this week
    }
    double phoneDist (eachDay &data) {
    }
    double schoolDist (eachDay &data) {
    }
    double socialDist (eachDay &data) {
    }
    double workDist (eachDay &data) {
    }

};

int main () {

    return 0;
}

//other files will have comments that are randomly picked to add as "feedback"
//to the calendar based on time distribution results

