#include <iostream>
#include <map>
#include <stack>
#include <sstream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

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
	int getRow() {
		return row;
	}
	char getCol() {
		return column;
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
					int a=s.top();
                    s.pop();
					int b=s.top();
                    s.pop();
					s.push(a+b);
				}
				else if (item=="*") {
					int a=s.top();
                    s.pop();
					int b=s.top();
                    s.pop();
					s.push(a*b);
				}
				else if (item=="-") {
					int a=s.top();
                    s.pop();
					int b=s.top();
                    s.pop();
					s.push(a-b);
				}
				else if (item=="/") {
					int a=s.top();
                    s.pop();
					int b=s.top();
                    s.pop();
					s.push(a/b);
				}
				else if (item=="abs"){
					int a=s.top();
					s.pop();
					int b= s.top();
					s.pop();
					s.push(fabs(a));
				}
				else if (item=="cos"){
					int a=s.top();
					s.pop();
					int b= s.top();
					s.pop();
					s.push(cos(a));
				}	
				else if (item=="sin"){
					int a=s.top();
					s.pop();
					int b= s.top();
					s.pop();
					s.push(sin(a));
				}	
				else if (item=="tan"){
					int a=s.top();
					s.pop();
					int b= s.top();
					s.pop();
					s.push(tan(a));
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

	string getText()
	{
		return value;
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
		//figure out the biggest element in the spreadsheet
			//for each element in spreadsheet #FIXED
				//get value or text #FIXED
				//determine the length of that value or text when printed #FIXED
				//store result in vector #FIXED
			//search for max value, store
	vector<int> stringSizes;
	map<Label, Cell*>::iterator it;
	for (it = cells.begin(); it != cells.end(); it++) {
		if(it->second->getType() != 'S')
		{
			string temp = to_string(it->second->getValue(this));
			temp.erase(temp.find_last_not_of('0')+1, string::npos);
			temp.erase(temp.find_last_not_of('.')+1, string::npos);
			stringSizes.push_back(temp.size());
		}
		else
		{
			stringSizes.push_back(it->second->getText().size());
		}
	}
	int biggestSize;
	sort(stringSizes.begin(), stringSizes.end(), greater<int>());
	if(stringSizes.size() > 0) {
	biggestSize = stringSizes[0];
	}	
		//figure out minimum row #
			//for each element in spreadsheet
				//grab its cell (by the throat) #FIXED
				//see the row number of the cell #FIXED
				//if row number is less than min, set as new min #FIXED
		int minRow = 239482399;
		for (it = cells.begin(); it != cells.end(); it++) {
			int temp = it->second->getLabel().getRow();
			if (temp < minRow) {
				minRow = temp;
			}	
		}
		//figure out maximum row #
		//for each element in spreadsheet
				//grab its cell (by the throat) #fixed
				//see the row number of the cell #fixed
				//if row number is more than max, set as new max #fixed
		int maxRow = 0;
		for (it = cells.begin(); it != cells.end(); it++) {
			int temp = it->second->getLabel().getRow();
			if (temp > maxRow) {
				maxRow = temp;
			}	
		}
		char minCol = 'Z';
		for (it = cells.begin(); it != cells.end(); it++) {
			char temp = it->second->getLabel().getCol();
			if (temp < minCol) {
				minCol = temp;
			}	
		}
		char maxCol = 'A';
		for (it = cells.begin(); it != cells.end(); it++) {
			char temp = it->second->getLabel().getCol();
			if (temp > maxCol) {
				maxCol = temp;
			}	
		}
		char c = minCol;
		//output header (A-Z) (setw will be column width determined from above)
		//setw(biggestSize)
		out << endl;
		out << "Row|  ";
		for (char c = minCol; c <= maxCol; c++) {
		out << setfill(' ') << setw(biggestSize-2) << c << "|  ";
		}
		out << endl;
		out << "---+";
		out << setfill('-');
		for (char c = minCol; c <= maxCol; c++) {
		out << setw(biggestSize) << "" << "+";
		}
		out << endl;
		//for each row
			//output row # |
		int newMinRow = minRow;
		for(newMinRow; newMinRow <= maxRow; newMinRow++) {
			out << setfill(' ') << newMinRow << " |";
			for (char c = minCol; c <= maxCol; c++) {
				string lab = string(1,c);
				lab += to_string(newMinRow); //concatenate string
				Label temp = Label(lab); //make into label!
				if(cells.count(temp) > 0) { // if thing exists					
				//for A-Z
				//output value if not null and |
						if (cells[temp]->getType() != 'S') {
							out << setfill(' ') << setw(biggestSize) << cells[temp]->getValue(this) << "|";
						}
						else {
							out << setfill(' ') << setw(biggestSize) << cells[temp]->getText() << "|";
						}	
					//print thing if string or value
				}
				else { // if no thing exists
					//print blank at column wide
					out << setfill(' ')  << setw(biggestSize) << "" << '|';
				}
		}
				out << endl;
				out << "---+";
				out << setfill('-');
				for (char c = minCol; c <= maxCol; c++) {
				out << setw(biggestSize) << "" << "+";
			}
			out << endl;
		}
		out << endl;
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
	  } else if (choice==4) {
		  s.print2D(cout);
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



	