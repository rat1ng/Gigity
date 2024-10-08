#include <assert.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

const int DefaultPQSize = 50;

template <class T>
class PQueue {
protected:
    T* pqelements;
    int count;
    int maxSize;
    void Adjust() {
        int j;
        T temp = pqelements[count - 1];
        for (j = count - 2; j >= 0; j--) {
            if (pqelements[j] <= temp) {
                break;
            } else {
                pqelements[j + 1] = pqelements[j];
            }
        }
        pqelements[j + 1] = temp;
    }

public:
    PQueue(int sz = DefaultPQSize) {
        maxSize = sz;
        count = 0;
        pqelements = new T[maxSize];
        assert(pqelements != NULL);
    }

    ~PQueue() {
        delete [] pqelements;
    }

    bool Insert(const T& x) {
        if (count == maxSize) {
            return true;
        }
        pqelements[count] = x;
        count++;
        Adjust();
    }

    bool RemoveMin(T& x) {
        if (count == 0) {
            return false;
        }
        x = pqelements[0];
        for (int i = 1; i < count; i++) {
            pqelements[i - 1] = pqelements[i];
        }
        count--;
        return true;
    }

    int getFront() {
        if (count == 0) {
            return false;
        } else {
            return pqelements[0];
        }
    }
};

int main(){
    int a, b, c;
    PQueue<int> example;
    example.Insert(6);
    example.Insert(5);
    example.Insert(4);
    example.Insert(1);
    example.Insert(2);
    example.Insert(66);
    example.Insert(88);
    example.Insert(999);
    example.RemoveMin(a);
    example.RemoveMin(b);
    example.RemoveMin(c);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}