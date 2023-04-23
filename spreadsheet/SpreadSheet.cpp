#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
/*  Features
 * Read a spreadsheet from a file
 * Write a spreadsheet to a file
 * 	Assume the user knows the file name
 * Formulas will be written in PostFix
 * 		=2 +3   -> 2 3 +
 * String fields
 * Formula
 * Number fields   3.14   1 
 * 
 * Name cells Letter->Number   "A6"  "A100" "Z100"
 * 	Letter column name
 * 	Number is the row
 * Menu of option
 * 	Add a cell
 * 	Remove a cell
 * 	Edit a cell
 * 	Calculate spreadsheet
 *  print spreadsheet
 *  Print2d Spreasheet
 */ 
 
class Label {
	char column;
	int row;
	public:
	Label(string newLabel="") {
		// Do the work of taking the Column and Row apart
		if (newLabel.size()>=2) {
		  column=newLabel[0];
		  row=stoi(newLabel.substr(1));
	    } else {
			column='?';
			row=-1;
		}
		//stringstream sin(newLabel);
		//sin>>column>>row;
	}
	bool operator <(const Label &other) const {
		if (column==other.column) 
		  return row<other.row;
		return column<other.column;
	}
	void print(ostream &out=cout) const {
		out << column << row;
	}
	void write(ostream &out) const {
	    print(out);
	}
	void read(istream &in) {
		in >> column >> row;
	}
};

class PrimordialSheet {
  public:
  virtual double getValue(Label l)=0;
};



class Cell{
	protected:
	Label label;
	public:
//	static PrimordialSheet *sheet;
//	static void setSheet(PrimordialSheet *newSheet) {
//		sheet=newSheet;
//	}
	Cell(Label newLabel) {  
		label=newLabel;
	}
	Label getLabel(){
		return label;
	}
	virtual void calculate(PrimordialSheet *sheet)=0;
	virtual double getNumber(){return 0.0;}
	virtual string getText(){return "";}
	virtual void print(ostream &out=cout) {
		label.print(out);
	}
	virtual void write(ostream &out) const =0;
	virtual void read(istream &in)=0;
	virtual bool isUpdated() { return true; }
	virtual void invalidate() {}
	virtual double getValue(PrimordialSheet *sheet) { return 0.0; } 
};

class Formula:public Cell {
	string formula;
	bool updated;
	double value;
	public:
	Formula(Label newLabel,string newFormula="") :Cell(newLabel){
		formula=newFormula;
		updated=false;
		value=0.0;
	}
	double getValue(PrimordialSheet *sheet) {
		if (!updated) calculate(sheet); 
		return value; 
	}
	bool isUpdated() {  return updated; }
	void invalidate() { updated=false; }
	void calculate(PrimordialSheet *sheet) {
	  stack<double> s;
      vector <string> strings;
      int position;
      string item;
      string temp = formula;
	  // If I need "A20"
	  // sheet->getValue(Label("A20"));
		// Re implement our push-down calculator for this formula
		// You first assignment is to implement this
		// HINT use the expression evaluation code from class as a
		// starting point
        while ((position=temp.find(" "))!= string::npos) {
            item=temp.substr(0,position);
            temp.erase(0,position+1);
            strings.push_back(item);

        }
        strings.push_back(temp);

        for (string item: strings)
        {
            bool isNum = true;
            for (int i = 0; i < item.length(); i++)
            {
                if (!isdigit(item[i]))
                {
                    isNum = false;
                }
            }

        if (isNum) { // its a number
				s.push(stoi(item));
			} else {
				if (item=="+") {
					int a=/*s.top();*/ s.top();
                    s.pop();
					int b=/*s.top();*/ s.top();
                    s.pop();
					s.push(a+b);
				}
				else if (item=="*") {
					int a=/*s.top();*/ s.top();
                    s.pop();
					int b=/*s.top();*/ s.top();
                    s.pop();
					s.push(a*b);
				}
				else if (item=="-") {
					int a=/*s.top();*/ s.top();
                    s.pop();
					int b=/*s.top();*/ s.top();
                    s.pop();
					s.push(a-b);
				}
				else if (item=="/") {
					int a=/*s.top();*/ s.top();
                    s.pop();
					int b=/*s.top();*/ s.top();
                    s.pop();
					s.push(a/b);
				}
                else
                {
                    s.push(sheet->getValue(Label(item)));
                }
			}
        }
        

	  label.print();
	  cout << " was calculated" << endl;
	  value=s.top();
      cout << value << endl;
	  updated=true;
	}
	void print(ostream &out=cout) {
		Cell::print(out);
		out << ':' << formula << endl;
	}
	void write(ostream &out) const {
        out <<formula << endl;
	}
	void read(istream &in) {
		getline(in,formula);
	}
};

class String:public Cell {
	// ToDo a lot more
};

class Number:public Cell {
	// ToDo a lot more
};

class Sheet:public PrimordialSheet {
	map<Label,Cell *> cells;
	public:
	double getValue(Label l) { return cells[l]->getValue(this); }
	void read(string filename) {
		ifstream in;
		in.open(filename);
        int count;
		in >> count;
		for (int i=0;i<count;i++){
			Label l;
			char dummy,type;
			l.read(in);
			in >> dummy >> type >> dummy;
			Formula *f=new Formula(l);
			f->read(in);
			cells[l]=f;
		}
		in.close();
	}
	void write(string filename) {
		ofstream out;
		out.open(filename);
        // Interesting code here
		out << cells.size() << endl;
		for (auto it=cells.begin();it!=cells.end();it++){
          it->first.write(out);
		  out << " F ";
		  it->second->write(out);
		}
		out.close();
	}
	void add(Cell *c) {
		cells[c->getLabel()]=c;
	}
	void calculate(PrimordialSheet *sheet) {
		for(auto it:cells) 
		  it.second->invalidate();
		for(auto it:cells) 
		  if(!it.second->isUpdated()) 
		    it.second->calculate(this);
				
//		for(auto it=cells.begin();it!=cells.end();it++) {
//			it->second->calculate();
	}
	void remove(Cell *c) {
		cells.erase(c->getLabel());
	}
	void update(Cell *c) {
		remove(c);
		add(c);
	}
	void print(ostream &out=cout) {
		for(auto it=cells.begin();it!=cells.end();it++) {
			// it->first; <- A label
			// it->second; <- A Cell *
			it->second->print(out);
		}
	}
	void print2D(ostream &out=cout) {
	}
};

Cell *addCellMenu() {
	string input;
	int choice=0; 
	cout << "[1] Add a Formula Cell" << endl;
	cout << "[2] Add a String Cell" << endl;
	cout << "[3] Add a Number Cell" << endl;
	getline(cin,input);
	stringstream sin=stringstream(input);
	sin >> choice;
    cout << "Enter the Cell Label (A20 for example)" << endl;
    string label;
    getline(cin,label);
	if (choice==1) {
        cout << "Enter a postfix expression formula (2 3 + for example)" << endl;
        string formula;
        getline(cin,formula);
        Formula *f=new Formula(label,formula);
        return (Cell *)f;
	} else if (choice==2) {
		string str;
		cout << "Enter a string for the cell" << endl;
		getline(cin,str);
		//String *s=new String(label,str);
		//return (Cell *)s;
	} else if (choice==3) {
	}
	return (Cell *)NULL;
}

int main() {
	Sheet s;
	// setSheet(&s);  //This is for the static sheet approach
	string input;
	int choice=0;
	/* Present a menu to the user of action they can take*/
	while (choice!=9) { 
	  cout << "[1] Add a Cell" << endl;
	  cout << "[2] Remove a Cell" << endl;
	  cout << "[3] Print" << endl;
	  cout << "[4] Print 2D" << endl;
	  cout << "[5] Calculate" << endl;
	  cout << "[6] Write Output file 'data.txt'" <<endl;
	  cout << "[9] Quit" << endl;
	  getline(cin,input);
	  stringstream sin=stringstream(input);
	  sin >> choice;
	  if (choice==1) {
         Cell *c;
         c=addCellMenu();
         s.add(c);  
	  } else if (choice==5) {
		  s.calculate(&s);
	  } else if (choice==6) {
		  s.write("data.txt");
	  }
	  if (choice==3) s.print();
    }
	return 0;
}
