#include <iostream>
#include <iomanip>

using namespace std;

class StackException {
	public:
	void describe() {
		cerr<< "Stack Exception occurred" << endl;
	}
};
//  head= 0x0100[Data:"Kim",next->NULL]
// 0x0090[Data:"Karl",next:0x0100]  -> 0x0100[Data:"Kim",next->NULL]
/* 0x0080[Data:"",next->0x0090] -> 
    0x0090[Data:"Karl",next:0x0100]  -> 
      0x0100[Data:"Kim",next->NULL]
*/
class LinkNode{
	string name;
	LinkNode *next;
	void outputHex(ostream &out,const LinkNode *add) const {
		long shortAdd=((long)add & 0xffff);
		out << setw(4) << setfill('0') << hex<< shortAdd<<
		  dec <<setfill(' '); 
	}
	public:
	LinkNode(string newName="",LinkNode *newNext=NULL) {
		name=newName;
		next=newNext;
	}
	void pop() {
		if (!empty()) {
			LinkNode *temp=next;
			next=temp->next;
			delete temp;
		} else throw StackException();
	}
	void push(string newName) {
		LinkNode *temp=new LinkNode(newName,next);
		//  head->[name:"",next:{????}]  temp->[name:"Kim",next:{????}]
        next=temp;
		//  head->[name:"",next:0x100]  temp->0x100[name:"Kim",next:{????}]
	}
	string top() {
		if (!empty()) 
		  return next->name;
		throw StackException();
	}
	bool empty() {
		return next==NULL;
	}
	friend ostream & operator <<(ostream &out,const LinkNode &list) {
		list.outputHex(out,&list);
		out << "[name:"<<list.name << ",next:";
		list.outputHex(out,list.next);
        out << "]";
		if(list.next!=NULL) 
		  out << "->" << *(list.next);
		return out;
	}
//	bool full() { // Reasonably unlimited  new fail because no memory
//	}
};

int main() {//  &  . dot notation   if  * -> arrow notation
	try {
	LinkNode head;
		head.push("Kim");
		head.push("Karl");
		cout << head << endl;
		head.pop();
		cout << head << endl;
		cout << "Top has values " << head.top() << endl;
		head.pop();	
		cout << head << endl;
		head.pop();
	    cout << head << endl;
    } catch (StackException &se) {
		se.describe();
	}
	return 0;
}
