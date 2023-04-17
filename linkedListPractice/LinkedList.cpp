#include <iostream>

using namespace std;

class Node {
    public:
        string data;
        Node *next;
    Node () {
        data = "";
        next = NULL;
    }
};

class LinkedList {
    Node *head;

    public:
    LinkedList() {
        head=NULL;
    }
    void push(string newData) {
        Node *newNode = new Node();
        newNode->data = newData;
        if (head == NULL) {
            head = newNode;
        }
        else {
            Node *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void pop() {
        Node *temp = 
    }
};