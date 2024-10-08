#include <iostream>
#include "LinearList.h"
using namespace std;

template <class T>
struct LinkNode{
    T data;
    LinkNode<T> * link;
    LinkNode(LinkNode<T> * ptr = NULL){
        link = ptr;
    }
    LinkNode(const T& item, LinkNode<T> * ptr = NULL){
        data = item;
        link = ptr;
    }
};

template <class T>
class List: public LinearList<T>{
protected:
    LinkNode<T> * first;

public:
    List(){
        first = new LinkNode<T>;
    }

    List(const T& x){
        first = new LinkNode<T>(x);
    }

    List(List<T>& L); //复制构造函数

    ~List(){
        makeEmpty();
    }

    void makeEmpty();

    int Length() const;

    LinkNode<T> * getHead()const{
        return first;
    }

    void setHead(LinkNode<T> * p){
        first = p;
    }

    LinkNode<T> * Search(T x);

    LinkNode<T> * Locate(int i);

    T * getData(int i);

    void setData(int i, T& x);

    bool Insert(int i, T& x);

    bool Remove(int i, T& x);

    bool IsEmpty()const{
        if (first->link == NULL){
            return true;
        } else {
            return false;
        }
    }

    bool IsFull()const{
        return false;
    }

    void Sort();

    void input();

    void output();
    
    List<T>& operator=(List<T>& L);
};

template <class T>
List<T>::List(List<T>& L){
    T value;
    LinkNode<T> * srcptr = L.getHead();
    LinkNode<T> * destptr = first = new LinkNode<T>;
    while (srcptr->link != NULL){
        value = srcptr->link->data;
        destptr->link = new LinkNode<T> (value);
        destptr = destptr->link;
        srcptr = srcptr->link;
    }
    destptr->link = NULL;
};

template <class T>
void List<T>::makeEmpty(){
    LinkNode<T> * q;
    while (first->link != NULL){
        q = first->link;
        first->link = q->link;
        delete q;
    }
};

template <class T>
int List<T>::Length()const{
    LinkNode<T> * p = first->link;
    int count = 0;

    while (p != NULL){
        p = p->link;
        count++;
    }
    return count;
};

template <class T>
LinkNode<T>* List<T>::Search(T x){
    LinkNode<T>* current = first->link;
    while (current != NULL){
        if (current->data == x){
            break;
        } else {
            current = current->link;
        }
    }
    return current;
};

template <class T>
LinkNode<T>* List<T>::Locate(int i){
    if(i < 0){
        return NULL;
    }
    LinkNode<T>* current = first;
    int k = 0;
    while (current != NULL && k < i){
        current = current->link;
        k++;
    }
    return current;
};

template <class T>
T* List<T>::getData(int i){
    if (i <= 0){
        return NULL;
    }
    LinkNode<T>* current = Locate(i);
    if (current == NULL){
        return NULL;
    } else {
        return *(current->data);
    }
};

template <class T>
bool List<T>::Insert(int i, T& x){
    LinkNode<T>* current = Locate(i);
    if (current == NULL){
        return false;
    }
    LinkNode<T>* newNode = new LinkNode<T>(x);
    if (newNode == NULL){
        cout << "存储分配错误！" << endl;
        exit(1);
    }
    newNode->link = current->link;
    current->link = newNode;
    return true;
};

template <class T>
bool List<T>::Remove(int i, T& x){
    LinkNode<T>* current = Locate(i - 1);
    if (current == NULL || current->link == NULL){
        return false;
    }
    LinkNode<T>* del = current->link;
    current->link = del->link;
    x = del->data;
    delete del;
    return true;
};

template <class T>
void List<T>::output(){
    LinkNode<T>* current = first->link;
    while (current != NULL){
        cout << current->data << endl;
        current = current->link;
    }
};

template <class T>
List<T>& List<T>::operator=(List<T>& L){
    T value;
    LinkNode<T>* srcptr = L.getHead();
    LinkNode<T>* destptr = first = new LinkNode<T>;
    while (srcptr->link != NULL){
        value = srcptr->link->data;
        destptr->link = new LinkNode<T>(value);
        destptr = destptr->link;
        srcptr = srcptr->link;
    }
    destptr->link = NULL;
    return *this; //假如说要A = B，则A为请求者，此时会自动产生一个指向A的指针，就是this，而A = *this
};
