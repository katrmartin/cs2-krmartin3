#include <iostream>
#include <iomanip>

using namespace std;

class QueueException {
	public:
	void describe() {
		cerr<< "Queue Exception occurred" << endl;
	}
};

class LinkNode{
	string name;
	LinkNode *next, *prev; //two pointers, up or down thru the list
	static void outputHex(ostream &out,const LinkNode *add) const {
		long shortAdd=((long)add & 0xffff);
		out << setw(4) << setfill('0') << hex<< shortAdd<<
		  dec <<setfill(' '); 
	}
	public:
	string getName() { return name; }
	LinkNode *getNext() { return next;}
	void setPrev(LinkNode *newPrev=NULL) { prev=newPrev; }
	void setName(string newName) { name=newName; }
	void setNext(LinkNode *newNext=NULL) { next=newNext; }
	LinkNode(string newName="",LinkNode *newNext=NULL, LinkNode *newPrev=NULL) {
		name=newName;
		next=newNext;
		prev=newPrev;
	}
	/*
	void pop() { //pop off the front of the queue
		if (!empty()) {
			LinkNode *temp=next;
			next=temp->next;
			delete temp;
		} else throw QueueException();
	}
	void push_back(string newName) { //put at the end of the queue
		LinkNode *temp=new LinkNode(newName,this->next,this);
		next->prev=temp;
        next=temp;
		prev=NULL;

		//  head->[name:"",next;(this->next),prev:{????}]
		//  head->[name:"",next:{????}]  temp->[name:"Kim",next:{????}]
		//  head->[name:"",next:0x100]  temp->0x100[name:"Kim",next:{????}]
	}
	*/
	string top() {
		if (!empty())  {
			LinkNode *p=this;
			while (p->next!=NULL) {
				p=p->next;
			}
		 return p->name;
		}
		throw QueueException();
	}
	bool empty() {
		return next==NULL && prev==NULL;
	}
	friend ostream & operator <<(ostream &out,const LinkNode &list) {
		list.outputHex(out,&list);
		out << "[name:"<<list.name << ",prev:";
		list.outputHex(out,list.prev);
		out << ",next:";
		list.outputHex(out,list.next);
        out << "]";
		if(list.next!=NULL) 
		  out << "->" << *(list.next);
		return out;
	}
//	bool full() { // Reasonably unlimited  new fail because no memory
//	}
};

class DoublyLinkedList {
	LinkNode *head, *tail;
	public:
	DoublyLinkedList(LinkNode *newHead=NULL, LinkNode *newTail=NULL) {
		head=newHead;
		tail=newTail;
	}
	void push_back(string name) {
		LinkNode *temp=new LinkNode(name, NULL, tail);
		if (tail!=NULL) {
			tail->setNext(temp);
		}
		tail=temp;
		if (head==NULL) head=temp; //head has same address as tail if head empty
	}
	string top() {
		if (head!=NULL) return head->getName();
		throw QueueException();
	}
	string back() {
		if (tail!=NULL) return tail->getName();
		throw QueueException();
	}
	void pop() {
		LinkNode *temp = head->getNext();
		if (temp!=NULL) {
			head=temp->getNext();
			free(temp);
		}
		if (temp==head)
			head->setPrev(NULL);
		// start: head-> Karl (next)-> Kim
		// free up house that stored Karl
		// end: head-> Kim
	}
	friend ostream & operator << (ostream &out, const DoublyLinkedList &dll) {
		out << "DoubleLink List Grounded Node [head:";
		LinkNode::outputHex(out,dll.head);
		out << ",tail:";
		LinkNode::outputHex(out,dll.tail);
		if(dll.head) //incomplete
	}
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
    } catch (QueueException &se) {
		se.describe();
	}
	return 0;
}
