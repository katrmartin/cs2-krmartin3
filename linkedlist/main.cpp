#include <iostream>

using namespace std;

//head = 0x0100[Data: "Kim", next-> NULL]
//0x0090[Data: "Karl", next->0x0100]   ->  0x0100[Data: "Kim", next-> NULL]
//data item and pointer pointing to next data item

class LinkNode{
    string name;
    LinkNode *next;
    public:
    LinkNode(string newName="", LinkNode *newNext=NULL) {
        name = newName;
        next = newNext;
    }    
    void push(string newName) {
        LinkNode *temp=new LinkNode(newName,next);
        next=temp;
    }
    void pop() {
        if (!empty()) {
            LinkNode *temp=next;
            next=temp->next;
            delete temp;
        }
    }
    bool empty() {
        return next==NULL;
    }
    
};

int main() {
// & . dot notation      if * -> arrow notation
    LinkNode *head = new LinkNode("Kim");
    head->push("Karl");
    /* grounded link list flavor
     * LinkNode head;
     * head.push("Kim");
     * head.push("Karl");
    */

    return 0;
}