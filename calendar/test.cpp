#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <iomanip>

using namespace std;


    int getRandomNumber(int min, int max) { 
        srand(time(NULL));
        int randNum = rand()%(max-min + 1) + min;
        cout << randNum <<endl;
            return randNum;
    }

class eachDay {
    protected:
    string dayOfWeek;
    string mood;
    double sleep, school, phone, social, work;
    public:
    string getDayOfWeek() { return dayOfWeek; }
    string getMood() { return mood; }
    double getSleep() { return sleep; }
    double getSchool() { return school; }
    double getPhone() { return phone; }
    double getSocial() { return social; }
    double getWork() { return work; }
    
    void readDay(ifstream &fin) {
        fin >> dayOfWeek;
        fin >> mood;
        fin >> sleep >> school >> phone >> social >> work;
        
    }
    double totalActivityHoursDay() {
        return (sleep + school + phone + social + work);
    }
    void output(ostream &out, ifstream &fin) {
        out << dayOfWeek << ": " << endl;
        out << "You were feeling " << mood << endl;
        out << endl;
        out << "Here's how you spent your time:" << endl;
        out << endl;
        out << "sleep: " << sleep << " hours    school: " << school << " hours    phone: " 
        << phone << " hours    social: " << social << " hours    work: " << work << " hours";
        out << endl;
        out << setfill('-') << setw(150) << " " << endl;

    }
};

class Week {
    public:
    vector <eachDay> theWeek;
    vector <string> allComments;
    void readWeek(ifstream &fin) {
        for (int i = 0; i < 7; i++) {
            eachDay temp;
            temp.readDay(fin);
            theWeek.push_back(temp);
        }
    }
    void output(ostream &out, ifstream &fin) {
        for (auto f: theWeek) {
            f.output(out, fin);
            out << endl;
        }
    }
    double totalActHoursWeek() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].totalActivityHoursDay();
        }
        return temp;       
    }
    double totalSleep() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].getSleep();
        }
        return temp;
    }
    double totalPhone() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].getPhone();
        }
        return temp;
    }
    double totalSchool() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].getSchool();
        }
        return temp;
    }
    double totalSocial() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].getSocial();
        }
        return temp;
    }
    double totalWork() {
        double temp = 0;
        for (int c = 0; c < theWeek.size(); c++) {
            temp += theWeek[c].getWork();
        }
        return temp;
    }

    string phoneComment(ifstream &fin) {
        vector <string> phoneComments;
        string phone="";
        double temp = totalPhone();
        fin.open("phoneComments.txt");
        for (int i = 0; i < 7; i++) {
            getline(fin, phone);
            phoneComments.push_back(phone);
        }
        int randIndex = getRandomNumber(0, phoneComments.size());
        //cout << randIndex << endl;
        phone = phoneComments[randIndex];
      
            string tempnew = to_string(temp);
            tempnew.erase(tempnew.find_last_not_of('0')+1, string::npos);
			tempnew.erase(tempnew.find_last_not_of('.')+1, string::npos);

            int index;
            index = phone.find("_");
            if (index != string::npos) {
                phone.replace(index, string("_").length(), tempnew);
            }
            allComments.push_back(phone);
            fin.close();
            return phone;
    }

    string socialComment(ifstream &fin) {
        vector <string> socialComments;
        string social="";
        double temp = totalSocial();
        fin.open("socialComments.txt");
        for (int i = 0; i < 6 ; i++) {
            getline(fin, social);
            socialComments.push_back(social);
        }
        if (temp < 14) {
            int randIndex = getRandomNumber(0,3);
            social = socialComments[randIndex];
        }
        else {
            int randIndex = getRandomNumber(3,5);
            social = socialComments[randIndex];
        }

            string tempnew = to_string(temp);
			tempnew.erase(tempnew.find_last_not_of('0')+1, string::npos);
			tempnew.erase(tempnew.find_last_not_of('.')+1, string::npos);

            int index;
            index = social.find("_");
            if (index != string::npos) {
                social.replace(index, string("_").length(), tempnew);
            }
                allComments.push_back(social);
            fin.close();
            return social;
    }
    string workComment(ifstream &fin) {
        vector <string> workComments;
        string work="";
        double temp = totalWork();
        fin.open("workComments.txt");
        for (int i = 0; i < 11; i++) {
            getline(fin, work);
            workComments.push_back(work);
        }
        if (temp = 0) {
            int randIndex = getRandomNumber(0,2);
            work = workComments[randIndex];
        }
        else if (temp < 40) {
            int randIndex = getRandomNumber(3,6);
            work = workComments[randIndex];
        }
        else {
            int randIndex = getRandomNumber(6,10);
            work = workComments[randIndex];            
        }

            string tempnew = to_string(temp);
			tempnew.erase(tempnew.find_last_not_of('0')+1, string::npos);
			tempnew.erase(tempnew.find_last_not_of('.')+1, string::npos);

            int index;
            index = work.find("_");
            if (index != string::npos) {
                work.replace(index, string("_").length(), tempnew);
            }
                allComments.push_back(work);
            fin.close();
            return work;
    }
    string schoolComment(ifstream &fin) {
        vector <string> schoolComments;
        string school="";
        double temp = totalSchool();
        fin.open("schoolComments.txt");
        for (int i = 0; i < 7 ; i++) {
            getline(fin, school);
            schoolComments.push_back(school);
        }
        if (temp > 17.5 ) {
            int randIndex = getRandomNumber(0,3);
            school = schoolComments[randIndex];
        }
        else if (temp < 17.5) {
            int randIndex = getRandomNumber(4,6);
            school = schoolComments[randIndex];
        }
            string tempnew = to_string(temp);
			tempnew.erase(tempnew.find_last_not_of('0')+1, string::npos);
			tempnew.erase(tempnew.find_last_not_of('.')+1, string::npos);

            int index;
            index = school.find("_");
            if (index != string::npos) {
                school.replace(index, string("_").length(), tempnew);
            }
                allComments.push_back(school);
            fin.close();
            return school;
    }
    string sleepComment(ifstream &fin) {
        vector <string> sleepComments;
        string sleep="";
        double temp = totalSleep();
        fin.open("sleepComments.txt");
        for (int i = 0; i < 9 ; i++) {
            getline(fin, sleep);
            sleepComments.push_back(sleep);
        }
        if (temp > 63 ) {
            int randIndex = getRandomNumber(0,3);
            sleep = sleepComments[randIndex];
        }
        else if (temp < 49) {
            int randIndex = getRandomNumber(5,8);
            sleep = sleepComments[randIndex];
        }
        else if (49 < temp < 63) {
            sleep = sleepComments[4];            
        }
            string tempnew = to_string(temp);
			tempnew.erase(tempnew.find_last_not_of('0')+1, string::npos);
			tempnew.erase(tempnew.find_last_not_of('.')+1, string::npos);

            int index;
            index = sleep.find("_");
            if (index != string::npos) {
                sleep.replace(index, string("_").length(), tempnew);
            }
                allComments.push_back(sleep);
            //cout << sleep << endl;
            fin.close();
            return sleep;
    }
    void doAllComments(ostream &out, ifstream &fin) {
        
        allComments.clear();
        phoneComment(fin);
        socialComment(fin);
        workComment(fin);
        schoolComment(fin);
        sleepComment(fin);
            for (int i = 0; i < allComments.size(); i++) {
                out << allComments[i] << endl;
            }
            
        }


};

class Calendar {
    public:
    vector <Week> weeks;
    void readData(ostream &out, ifstream &fin) {
        string week;
        while (getline(fin, week)) {
            Week temp;
            temp.readWeek(fin);
            weeks.push_back(temp);
            fin.ignore();
            fin.ignore();
            

        }
    }
    void output(ostream &out, ifstream &fin) {
        int i = 1;
        for (auto w: weeks) {
            out << setfill(' ') << setw(50) << " ";
            out << "##### WEEK " << i << " #####" << endl;
            out << setfill(' ') << setw(35) << " ";
            out << " (and some extra comments you didn't ask for. Enjoy!)" << endl;
            out << setfill('=') << setw(150) << " " << endl;
            out << setw(150) << " " << endl;
            out << endl;
            w.output(out, fin);
            out << endl;
            srand(time(NULL));
            w.doAllComments(out, fin);
            out << endl;
            i++;
            //comments not outputting
            //also want to do percentage of time spent on activity based on total hours of activity given
        }

    }

    
    //format output for calendar
    //print onto file
    //file is named ex. Week of 4/30 - 5/7
    //perhaps put interactive menu here?
};

int main() {
    ifstream fin;
    ofstream fout;
    string filename;
    

    string sen1 = "Hello! Welcome to the Completely Normal Time Management Calendar!";
    string sen2 = "A sample .txt file is provided to show you how to format your data.";
    string sen3 = "Please enter your filename with your data: ";

/*
cout << endl;
    for (auto c: sen1) {
        cout << c;
        cout.flush();
        usleep(75000);
    }
    cout << endl;
    for (auto c: sen2) {
        cout << c;
        cout.flush();
        usleep(75000);
    }
    cout << endl;
    for (auto c: sen3) {
        cout << c;
        cout.flush();
        usleep(75000);
    }
    */
    cout << endl;
    cin >> filename;
    cin.ignore();
    cout << endl;
    cout << "Great!" << endl;

    fin.open(filename);
    Calendar calendar;
    calendar.readData(fout, fin);
    fin.close();

    string sen4 = "Now enter a filename to name your new calendar!";
    for (auto c: sen4) {
        cout << c;
        cout.flush();
        usleep(75000);
    }
    cout << endl;
    cin >> filename;
    cin.ignore();
    fout.open(filename);

    calendar.output(fout, fin);   

    //cout << calendar.weeks[0].sleepComment(fin) << endl;
    //cout << calendar.weeks[0].socialComment(fin) << endl;
    //cout << calendar.weeks[0].workComment(fin) << endl;
    //cout << calendar.weeks[0].phoneComment(fin) << endl;
    //cout << calendar.weeks[0].schoolComment(fin) << endl;





    string sen5 = "Check out your new time management calendar!";

    for (auto c: sen5) {
        cout << c;
        cout.flush();
        usleep(75000);
    }
    cout << endl;







cout << endl;

    

    return 0;
}