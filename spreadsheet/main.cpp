#include <iostream>
#include <string>
#include <map>

using namespace std;
/* Features:
 * read a spreadsheet from a file
 * write a spreadsheet to a file
 *  assume the user knows the file name
 * formulas will be written in postfix
 *      = 2 + 3  ->  2 3 +
 * string fields
 * formula
 * number fields    3.14    1
 * 
 * name cells Letter->Number combo "A6" "A100" "Z100"
 *  Letter column name
 *  Number is the row
 * menu of options:
 *  add a cell
 *  remove a cell
 *  edit a cell
 *  calculate spreadsheet
 *  print spreadsheet
 *  print 2d spreadsheet
*/

class Label {
    char column;
    int row;
    public:
    bool operator <(const Label &other) const {
        if (column==other.column)
            return row<other.row;
        else return column<other.column;
    }
};

class Cell {
    Label label;
    public:
    virtual void calculate()=0;
    virtual double getNumber() {return 0.0;}
    virtual string getText() {return "";}
};

class Formula:public Cell {
    string formula;
    public:
    void calculate() {
        //reimplement our push-down calculator for this formula
    }
};

class String:public Cell {
    //ToDo a lot more
};

class Number:public Cell {
    //ToDo a lot more
};

class Sheet {
    map<Label,Cell *> cells;
    public:
    void add(Cell *c) {

    }
    void remove(Cell *c) {

    }
    void update(Cell *c) {
        
    }
    void read(string filename) {

    }
    void write(string filename) {

    }
    void print(ostream &out) {

    }
    void print2D(ostream &out) {

    }


};

int main() {
    Sheet s;
    // present a menu to the user of action they can take
    // [1] read a file
    // [2] write a file
    // [3] print
    // [4] print 2D
    // [5] add a cell
    cout << "Hello CSCI 112" << endl;
    return 0;
}