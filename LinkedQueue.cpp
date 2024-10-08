#include <iostream>
#include "LinkedList.h"
#include "Queue.h"

using namespace std;

template <class T>
class LinkedQueue: public Queue<T> {
protected:
    LinkNode<T>* front;
    LinkNode<T>* rear;

public:
    LinkedQueue() {
        rear = nullptr;
        front = nullptr;
    }
    ~LinkedQueue() {
        makeEmpty();
    };
    bool EnQueue(const T& x);
    bool DeQueue(T& x);
    bool getFront(T& x);
    void makeEmpty();
    bool IsEmpty() const {
        if (front == NULL) {
            return true;
        } else {
            return false;
        }
    }
    bool IsFull() const {
        return false;
    }
    int getSize() const;
};


template <class T>
void LinkedQueue<T>::makeEmpty() {
    LinkNode<T>* p;
    while (front != NULL) {
        p = front;
        front = front->link;
        delete p;
    }
};

template <class T>
bool LinkedQueue<T>::EnQueue(const T& x) {
    if (front == NULL) {
        front = rear = new LinkNode<T>(x);
        if (front == NULL) {
            return false;
        }
    } else {
        rear->link = new LinkNode<T>(x);
        if (rear->link == NULL) {
            return false;
        }
        rear = rear->link;
    }
    return true;
};

template <class T>
bool LinkedQueue<T>::DeQueue(T& x) {
    if (IsEmpty() == true) {
        return false;
    }
    LinkNode<T>* p = front;
    x = front->data;
    front = front->link;
    delete p;
    return true;
};

template <class T>
bool LinkedQueue<T>::getFront(T& x) {
    if (IsEmpty() == true) {
        return true;
    }
    x = front->data;
    return true;
};

template <class T>
int LinkedQueue<T>::getSize() const {
    LinkNode<T>* p = front;
    int k = 0;
    while (p != NULL) {
        p = p->link;
        k++;
    }
    return k;
};


int main() {
    int a = 4, b, c, d, e;
    LinkedQueue<int> example;
    example.EnQueue(a);
    example.getFront(b);
    cout << b << endl;
    c = example.getSize();
    cout << c << endl;
    example.DeQueue(d);
    cout << d << endl;

    return 0;
}