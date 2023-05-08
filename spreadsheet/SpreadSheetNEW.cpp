#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>

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
	virtual char getType() const =0; // Get the type of a cell 
	virtual void calculate(PrimordialSheet *sheet){};
	virtual void write(ostream &out) const =0;
	virtual void read(istream &in)=0;
	virtual double getNumber(){return 0.0;}
	virtual string getText(){return "";}
	virtual void print(ostream &out=cout) {
		label.print(out);
	}
	virtual bool isUpdated() { return true; }
	virtual void invalidate() {}
	virtual double getValue(PrimordialSheet *sheet) { return 0.0; }
	virtual void print2D(ostream &out=cout){}
};

class Formula:public Cell {
	string formula;
	bool updated;
	double value;
	public:
	char getType() const { return 'F'; }
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
	  stringstream sin(formula);
	  string input;
	  sin >> input;
		while (!sin.fail()) {
			//cout << "Input is " << input <<endl;
			if ((input[0]>='0' && input[0]<='9') || input[0]=='.')// its a number
				s.push(stod(input));
			else if (input[0]>='A' && input[0]<='Z')
				s.push(sheet->getValue(input));
			else {
				if (input=="+"|| input=="-" || input=="*"|| input=="/") {
					double a=s.top(); s.pop();
					double b=s.top(); s.pop();
					if (input=="+") s.push(a+b);
					else if (input=="*") s.push(a*b);
					else if (input=="-") s.push(b-a);
					else if (input=="/") s.push(b/a);
			    } else if (input=="cos" || input=="abs") {
					double a=s.top(); s.pop();
                    if (input=="cos") s.push(cos(a));
                    else if (input=="abs") s.push(fabs(a));					
				}
			} 
			sin >> input;
		}
		cout << s.top() << endl;
	  label.print();
	  value=s.top();
	  cout << " was calculated " << value << endl;
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
		if (formula[0]==' ') formula=formula.substr(1);
	}
};

class String:public Cell {
	string value;
	public:
	String(Label l,string newValue=""):Cell(l) { value=newValue; }
	char getType() const { return 'S'; }
	void write(ostream &out) const {  out <<  value << endl; }
	void read(istream &in){ 
		getline(in,value);
		if (value[0]==' ') value=value.substr(1); 
	}
	void print(ostream &out=cout) {
		Cell::print(out);
		out << ":'" << value<<"'" << endl;
	}
};

class Number:public Cell {
	double value;
	public:
	Number(Label l,double newValue=0.0):Cell(l) { value=newValue;}
	char getType() const  { return 'N'; }
	void write(ostream &out) const { out << value << endl; }
	void read(istream &in){ in >> value; }
	void print(ostream &out=cout) {
		Cell::print(out);
		out << ':' << value << endl;
	}
	virtual double getValue(PrimordialSheet *sheet) { return value; }
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
			char /* dummy,*/type;
			l.read(in);
			in >> type ;
			Cell *c;
			cerr << "The type read is " << type << endl;
			if (type=='F') { c=new Formula(l); }
		    else if (type=='N') { c=new Number(l); } 
			else if (type=='S') { c=new String(l);}
			c->read(in);
			cells[l]=c;
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
          out << ' ' << it->second->getType() <<' ';
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
	void remove(string labelName) {
		Label l(labelName);
		cells.erase(l);
	}
	/*void update(Cell *c) {
		remove(c->getLabel());
		add(c);
	}*/
	void print(ostream &out=cout) {
		for(auto it=cells.begin();it!=cells.end();it++) {
			// it->first; <- A label
			// it->second; <- A Cell *
			it->second->print(out);
		}
	}
	void print2D(ostream &out=cout) {
		//toDO
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
	string str;
	Cell *c=NULL;
	string prompts[3]={
	    "Enter a postfix expression formula (2 3 + for example)",
		"Enter a string for the cell",
		"Enter the number for the cell"};
	cout << prompts[choice-1] <<endl;
    getline(cin,str);
	if (choice==1)  c=new Formula(label,str);
	else if (choice==2)  c=new String(label,str);
	else if (choice==3)  c=new Number(label,stod(str));
	return c;
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
	  cout << "[7] Read the file 'data.txt'"<<endl;
	  cout << "[9] Quit" << endl;
	  getline(cin,input);
	  stringstream sin=stringstream(input);
	  sin >> choice;
	  if (choice==1) {
         Cell *c;
         c=addCellMenu();
         s.add(c);  
	   } else if (choice==2) {
		  cout << "Enter the cell label to delete"<< endl;
		  getline(cin,input);
		  s.remove(input); 
	  } else if (choice==3){ 
		  s.print();
	  } else if (choice==5) {
		  s.calculate(&s);
	  } else if (choice==6) {
		  s.write("data.txt");
	  } else if (choice==7) {
		  s.read("data.txt");
	  }
    }
	return 0;
}
