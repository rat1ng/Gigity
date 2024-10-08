#include <assert.h>
#include <iostream>
#include "Queue.h"

using namespace std;

template <class T>
class SeqQueue: public Queue<T> {
private:
    int rear, front;
    T* elements;
    int maxSize;

public:
    SeqQueue(int sz = 10);
    ~SeqQueue() {
        delete [] elements;
    }
    bool EnQueue(const T& x);
    bool getFront(T& x);
    bool DeQueue(T& x);
    void makeEmpty() {
        front = rear = 0;
    }
    bool IsEmpty() const {
        if (front == rear) {
            return true;
        } else {
            return false;
        }
    }
    bool IsFull() const {  
        return (rear + 1) % maxSize == front;  
    }
    int getSize() const {
        return (rear - front + maxSize) % maxSize;
    }
};


template <class T>
SeqQueue<T>::SeqQueue(int sz) {
    front = 0;
    rear = 0;
    maxSize = sz;
    elements = new T[maxSize];
    assert (elements != NULL);
};

template <class T>
bool SeqQueue<T>::EnQueue(const T& x) {
    if (IsFull() == true) {
        return false;
    }
    elements[rear] = x;
    rear = (rear + 1) % maxSize;
    return true;
};

template <class T>
bool SeqQueue<T>::DeQueue(T& x) {
    if (IsEmpty() == true) {
        return false;
    }
    x = elements[front];
    front = (front + 1) % maxSize;
    return true;
};

template <class T>
bool SeqQueue<T>::getFront(T& x) {
    if (IsEmpty() == true) {
        return false;
    }
    x = elements[front];
    return true;
};



int main() {
    int a = 5, b, c = 55, d, e;
    SeqQueue<int> example;
    example.EnQueue(a);
    example.EnQueue(c);
    example.getFront(b);
    cout << b << endl;
    example.DeQueue(d);
    cout << d << endl;
    example.DeQueue(e);
    cout << e << endl;    
    cout << example.IsEmpty() << endl;
    cout << example.IsFull() << endl;
    cout << example.getSize() << endl;
    return 0;

}