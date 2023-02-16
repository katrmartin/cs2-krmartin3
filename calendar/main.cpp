#include <iostream>
#include <string>
#include <vector>

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
private:
    int m_day;
    int m_month;

public:
    //get, set, formatting functions
};

class Day {
private:
    double m_sleep;
    double m_phone;
    double m_school;
    double m_social;
public:
//get, set functions

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
    vector <Day> days;
    //days[MONDAY].getFromUser()
public:
//functions
};

int main () {

    return 0;
}

//another file will have comments that are randomly picked to add as "feedback"
//to the calendar based on time distribution results