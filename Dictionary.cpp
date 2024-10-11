#include <assert.h>
#include <iostream>
using namespace std;

template <class E, class K>
struct ChainNode {
    E data;
    K key;
    ChainNode<E, K>* link;
    ChainNode() {
        link = nullptr;
    }
    ChainNode(E& el, K& kl, ChainNode<E, K>* next = nullptr) {
        data = el;
        key = kl;
        link = next;
    }
};

template<class E, class K>
class SortedChain {
private:
    ChainNode<E, K>* first;
public:
    SortedChain() {
        first = new ChainNode<E, K>;
        assert(first != NULL);
    }
    ~SortedChain() {}
    ChainNode<E, K>* Search(const K kl) const {
        ChainNode<E, K>* p = first->link;
        while (p != NULL && p->key < kl) {
            p = p->link;
        }
        if (p != NULL && p->key == kl) {
            return p;
        } else {
            return NULL;
        }
    }
    void Insert(K kl, E& el) {
        ChainNode<E, K>* p = first->link;
        ChainNode<E, K>* pre = first;
        ChainNode<E, K>* newNode;
        while (p != NULL && p->key < kl) {
            pre = p;
            p = p->link;
        }
        if (p != NULL && p->key == kl) {
            p->data = el;
            return;
        }
        newNode = new ChainNode<E, K>(el, kl);
        if (newNode == NULL) {
            cout << "存储分配失败" << endl;
            exit(1);
        }
        newNode->link = p;
        pre->link = newNode;
    }
    bool Remove(const K kl, E& el) {
        ChainNode<E, K>* p = first->link;
        ChainNode<E, K>* pre = first;
        while (p != nullptr && p->key < kl) {
            pre = p;
            p = p->link;
        }
        if (p != nullptr && p->key == kl) {
            pre->link = p->link;
            el = p->data;
            delete p;
            return true;
        } else {
            return false;
        }
    }
    ChainNode<E, K>* Begin() {
        return first->link;
    }
    ChainNode<E, K>* Next(ChainNode<E, K>* current) const {
        if (current != NULL) {
            return current->link;
        } else {
            return NULL;
        }
    } 
};

int main() {
    SortedChain<int, int> chain;
    ChainNode<int, int>* node;
    int a = 10;
    int b = 20;
    int c = 115;

    chain.Insert(10, a);
    chain.Insert(20, b);
    chain.Insert(15, c);
    node = chain.Search(15);

    if (node != nullptr) {
        cout << node->data << endl;
    } else {
        cout << "fuck you" << endl;
    }
    return 0;
}