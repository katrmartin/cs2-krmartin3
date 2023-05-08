#include <iostream>

using namespace std;

class Person {
	string first,last;
	int FICO;
	int salary;
	public:
	Person(string _first="",string newLast="",int newFICO=0,int newSalary=0) {
		first=_first;
		last=newLast;
		FICO=newFICO;
		salary=newSalary;
	}
	bool operator <(const Person &other) const {
		/*if (last==other.last) 
		  return first<other.first;
		else
		  return last<other.last;*/
		return FICO<other.FICO;
	}
	friend ostream & operator <<(ostream &out,const Person &p) {
		return out << "First: " << p.first << " Last: " << p.last <<endl
		  << "FICO: " << p.FICO << " Salary: " << p.salary << endl;
	}
	//friend istream & operator >>(istream &in,Person &p) {
	//}
	bool operator >(const Person &other) const {
		return other<(*this);
	}
	bool operator !=(const Person &other) const {
		return other<(*this) || (*this)<other;
	}
	bool operator ==(const Person &other) const {
		return !((*this)!=other);
	}
	bool operator <=(const Person &other) const {
		return (*this)<other || (*this)==other;
	}
	bool operator >=(const Person &other) const {
		return (*this)>other || (*this)==other;
	}
};

//Karl 420
//Kim 820
//Kaleb 100


	// log2(1 000 000)  -> log(1 000 000)/log(2) 
	
//	name="C2",value="=3 4 + C2 -!"
// map<CellName,SpreadSheetCell>

class BinaryNode {
	Person p; //aggregation
	//string key,value;
	//pair<Person,Person>
	//map<Person,Person>
	BinaryNode *left,*right;      // less , more
	public:
	BinaryNode(const Person &newP,BinaryNode *newLeft=NULL,BinaryNode *newRight=NULL) {
		p=newP;
		left=newLeft;
		right=newRight;
	}
	BinaryNode(const BinaryNode &other) {
		// Walk the binary tree in infix order
		// Left then node itself then Right side
	}
			/*           A
			 *          / \
			 *         B   C
			 *        /  \  \
			 *        D   E  J
			 *       /   / \
			 *      F    H  I
             * 
             *  ORDER: F D B H E I A C J
			 */ 

	void remove(const Person &target,BinaryNode *parent=NULL) {
		//parent=this;
		if (p==target) { //if we are the target
/* Somewhat understandable version			  
              // 2 Children
			  if (left!=NULL && right!=NULL) {
				left->add(right);
				if (parent->left==this) parent->left=left;
				if (parent->right==this) parent->right=left; 
			  } 
			  // 0 or 1 child
			  else {
				  BinaryNode *child=NULL;
				  if (right!=NULL) child=right;
				  if (left!=NULL) child=left;
				  if (parent->left==this) parent->left=child;
				  if (parent->right==this) parent->right=child; 
			  } 
*/            BinaryNode *child=NULL;  //make child pointer
			  if (left!=NULL && right!=NULL) { //if we have two kids, add the right kid as a kid of left. make child points to left kid
				left->add(right);
				child=left;
              }
			  else if (right!=NULL) child=right; //if we have one kid & its right, child points to right
		      else if (left!=NULL) child=left; //same as above but left
			  if (parent->left==this) parent->left=child; //if we are our parent's left kid, replace parent's left kid with our child
			  if (parent->right==this) parent->right=child; //same as above but right
			  delete this; //kill ourself
		}
		if (target<p) { //if target is less than us
			if (left!=NULL) return left->remove(target,this); //if we have a left child, have our left child call the remove function, with the same target, and ourselves as a parent
		} else {
			if(right!=NULL) return right->remove(target,this); //same as above but right child
		}
	}
	void add(BinaryNode *temp) {
		if (temp->p<p) { // go to the left
			if (left==NULL) left=temp; //if we no have left child, make temp our left child
			else left->add(temp); //else our left child calls add with temp
		} else {  // go to the right
			if (right==NULL) right=temp;
			else right->add(temp);
		}
	}
	void add(const Person &newP){ //make person a binary node
		BinaryNode *temp=new BinaryNode(newP);
		add(temp); //call the other add
	}
	Person find(int FICO) {
		Person target("","",FICO);
		if (p==target) return p;
		if (target<p) {
			if (left!=NULL) return left->find(FICO);
			else return target;
		} else {
			if(right!=NULL) return right->find(FICO);
			else return target;
		}
	}
	friend ostream & operator <<(ostream &out,const BinaryNode *value) {
		out << value->p << 
		  "left" << hex << (long)value->left << 
		  "right " << hex << (long)value->right << dec << endl;
		  if (value->left!=NULL) out << value->left;
		  if (value->right!=NULL) out << value->right;
		return out;
	} 
};

/*           Karl 420
           /       \
      Kaleb 100     Kim 820
                    /
                 John 560
*/
int main() {
  BinaryNode root(Person("Karl","Castleton",420,80000));
  cout<< "------" << endl << &root;
  
  root.add(Person("Kim","Castleton",820,65000));
  root.add(Person("Kaleb","Castleton",100,20000));
  cout << "------" <<endl << &root;

  root.add(Person("John","Doe",560,40000));
  cout << "------" <<endl << &root;  

  Person p=root.find(820);
  cout << p;
  
  root.remove(Person("","",820,0));
  cout << "Removing Kim" << endl;
  cout << &root;
  cout << "Removing Kaleb" << endl;
  root.remove(Person("","",100,0));
  cout << &root;
  
}
