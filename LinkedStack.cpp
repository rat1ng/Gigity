#include <iostream>
#include <assert.h>
#include "LinkedList.h"
#include "stack.h"

template <class T>
class LinkedStack: public Stack<T>{
private:
    LinkNode<T>* top;

public:
    LinkedStack(){
        top = nullptr; //nullptr是空指针
    }
    
    ~LinkedStack(){
        makeEmpty();
    }
    
    void Push(const T& x);
    
    bool Pop(T& x);
    
    bool getTop(T& x);
    
    bool IsEmpty()const{
        if (top == NULL){
            return true;
        } else {
            return false;
        }
    }

    bool IsFull() const {
        return false;
    }    
    
    int getSize()const;

    void makeEmpty();
};

int main(){
    int a, b, c, d, e;
    LinkedStack<int> example;

    example.Push(5);
    example.Push(65);
    example.Push(55);
    example.Push(543);
    example.Push(566);
    a = example.getSize();
    example.Pop(b);
    cout << a << endl;
    cout << b << endl;

    example.getTop(e);
    cout << e << endl;
    return 0;
}

template <class T>
void LinkedStack<T>::makeEmpty(){
    LinkNode<T>* p;
    while (top != NULL){
        p = top;
        top = top->link;
        delete p;
    }
};

template <class T>
void LinkedStack<T>::Push(const T& x){
    top = new LinkNode<T>(x, top);
    assert(top != NULL);
};

template <class T>
bool LinkedStack<T>::Pop(T& x){
    if (IsEmpty() == true){
        return false;
    }
    LinkNode<T>* p = top;
    top = top->link;
    x = p->data;
    delete p;
    return true;
};

template <class T>
bool LinkedStack<T>::getTop(T& x){
    if (IsEmpty() == true){
        return false;
    }
    x = top->data;
    return true;
};

template <class T>
int LinkedStack<T>::getSize()const{
    LinkNode<T>* p = top;
    int k = 0;
    while(p != NULL){
        p = p->link;
        k++;
    }
    return k;
};

