#include <iostream>
#include <cassert>
#include <queue>

using namespace std;

class QueueException {
    public:
    void describe() {
        cerr << "Queue exception occurred" << endl;
    }
};

const int MAXQUEUE = 128; //100
class Queue {   
    int head, tail;
    int values[MAXQUEUE];
    int next(int position) {
//      return (position+1)%MAXQUEUE;
        return (position+1)&(MAXQUEUE-1);
    }
    public:
    Queue() {
        head = 0;
        tail = 0;
    }
    int front() {
        if (!isEmpty())
            return values[head];
        else throw QueueException();

    }
    void push(int value) {
        if (!isFull()) {
            values[tail] = value;
            tail = next(tail);
        }
        else throw QueueException();
    }
    void pop() {
        if (!isEmpty())
            head = next(head);
        else throw QueueException();

    }
    bool isFull() {
        return next(tail) == head;
    }
    bool isEmpty() {
        return head == tail; //if head = tail, then that means there's
        //no values in the queue
    }
};

/* Queue First-In First-Out
 * 0        <- head <- tail
 * 1
 * ...
 * 98
 * 99
 * */

// cout << 5*(6+1) << endl;
// 5 6 1 + * !
// cout << 5*6+1 << endl;
//5 6 * 1 + !

int main() {
//  Queue q;
    queue<int> q;
//  try {
        q.push(23);
        q.push(47);
        cout << q.front() << endl;
        q.pop();
        cout << q.front() << endl;
        q.pop();
        q.front();

//   } catch(QueueException &qe) {
//      qe.describe();
//   }



    return 0;
}