#include <assert.h>
#include <iostream>

const int DefaultSize = 50;

template <class T>
class bitSet {
private:
    int setSize;
    int vectorSize;
    unsigned short * bitVector;

public:
    bitSet(int sz = DefaultSize) {
        setSize = sz;
        assert(setSize > 0);
        vectorSize = (setSize + 15) >> 4; // 假如说sz是10，则得出vectorSize为(10+15)//16=1，说明1位v就能装下sz
        bitVector = new int[vectorSize];
        assert(bitVector != NULL);
        for (int i = 0; i < vectorSize; i++) {
            bitVector[i] = 0;
        }
    }
    bitSet(const bitSet<T>& R) {
        setSize = R.setSize;
        vectorSize = R.vectorSize;
        bitVector = new int[vectorSize];
        assert(bitVector != NULL);
        for (int i = 0; i < vectorSize; i++) {
            bitVector[i] = R.bitVector[i];
    }
    ~bitSet() {
        delete [] bitVector;
    }
    void makeEmpty() {
        for (int i = 0; i < vectorSize; i++) {
            bitVector[i] = 0;
        }
    }
    int getMember(const T x) {
        int ad = x / 16;
        int id = x % 16;
        unsigned short elem = bitVector[ad];
        return int ((elem >> (15 - id)) & 1);
    }
    void putMember(const T x, int v) {}
    bool addMember(const T x) {}
    bool delMember(const T x) {}
    bitSet<T>& operator = (const bitSet<T>& R) {}
    bitSet<T> operator + (const bitSet<T>& R) {}
    bitSet<T> operator * (const bitSet<T>& R) {}
    bitSet<T> operator - (const bitSet<T>& R) {}
    bool Contains(const T x) {}
    bool operator == (bitSet<T>& R) {}
};