#include <assert.h>
#include <iostream>
#include "stack.h" //"stack.h"不是在自带中找的,所以必须用""

using namespace std;

const int stackIcreament = 20;

template <class T> //模板T，可代表char,int等一切类型
class SeqStack: public Stack<T>{
private:
    T * elements;
    int top;
    int maxSize;
    void overflowProcess();

public:
    SeqStack(int sz = 50); //构造函数

    ~SeqStack(){
        delete [] elements;  //析构函数
    }

    void Push(const T& x);

    bool Pop(T& x); //返回栈顶元素出栈后的现栈顶元素

    bool getTop(T& x);

    bool IsEmpty() const { //const保证函数不改动任何东西，只做自己的事情
        if (top == -1){
            return true;
        } else {
            return false;
        }
    }

    bool IsFull() const {
        if (top == maxSize - 1){
            return true;
        } else {
            return false;
        }
    }

    int getSize() const {
        return top + 1;
    }

    void MakeEmpty(){
        top = -1;
    }

    void showStack();
};

template <class T>
SeqStack<T>::SeqStack(int sz){
    top = -1;
    maxSize = sz;
    elements = new T[maxSize];
    assert(elements != NULL); //assert为断言，方便
};

template <class T>
void SeqStack<T>::overflowProcess(){
    T * newArray = new T[maxSize + stackIcreament];
    if (newArray = NULL){
        cout << "存储分配失败!" << endl;
        exit(1); 
    }
    for (int i = 0; i <= top; i++){
        newArray[i] = elements[i];
    }
    maxSize = maxSize + stackIcreament;
    delete [] elements;
    elements = newArray;
};

template <class T>
void SeqStack<T>::Push(const T& x){ //这里const保证x不会被修改
    if (IsFull() == true){
        overflowProcess();
    }
    top += 1;
    elements[top] = x; //element是指针，element[top]是值，x也是值
};

template <class T>
bool SeqStack<T>::Pop(T& x){ //& x = a，则只要动x，a也会动，就像鲁迅和周树人
    if (IsFull() == true){
        return false;
    }
    top -= 1;
    x = elements[top];
    return true;
};

template <class T>
bool SeqStack<T>::getTop(T& x){
    if (IsEmpty() == true){
        return false;
    }
    x = elements[top];
    return true;
};

template <class T>
void SeqStack<T>::showStack(){
    for (int i = 0; i <= top; i++){
        cout << i << ": " << elements[i] << endl;
    }
};


int main(){
    int a, b, c, d, e, f, g;
    SeqStack<int> example;

    example.Push(10);
    example.Push(11);
    example.Push(12);


    example.showStack();

    example.Pop(a);
    example.getTop(b);
    c = example.getSize();
    bool m = example.IsEmpty();

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << m << endl;
    example.Pop(d);
    example.Pop(e);
    bool n = example.IsEmpty();
    cout << n << endl;
    return 0;
}