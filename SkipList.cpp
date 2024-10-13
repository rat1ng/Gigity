#include <iostream>
const int DefaultSize = 100;

template <class E, class K>
struct SkipNode {
    E data;
    K key;
    SkipNode<E, K>** link;
    SkipNode(int size = DefaultSize) {
        link = new SkipNode<E, K>* [size];
        if (link == NULL) {
            cout << "存储分配失败" << endl;
            exit(1);
        }
    }
    ~SkipNode() {
        delete [] link;
    }
};

template <class E, class K>
class SkipList {
private:
    int maxLevel;
    int Levels;
    K TailKey;
    SkipNode<E, K>* head;
    SkipNode<E, K>* tail;
    SkipNode<E, K>** last;
    int Level() {
        int lev = 0;
        while (rand() <= RAND_MAX/2) lev++;
        return (lev < maxLevel) ? lev : maxLevel;
    };
    SkipNode<E, K>* SaveSearch(const K kl) {
        if (kl > TailKey) return NULL;
        SkipNode<E, K>* p = head;
        for (int i = Levels; i>= 0; i--) {
            while (p->link[i]->data < kl) {
                p = p->link[i];
            last[i] = p;
            }
            last[i] = p;
        }
        return p->link[0];
    }
public:
    SkipList(K large, int maxLev = DefaultSize) {
        maxLevel = maxLev;
        TailKey = large;
        Levels = 0;
        head = new SkipNode<E, K>(maxLevel + 1);
        tail = new SkipNode<E, K>(0);
        last = new SkipNode<E, K>* [maxLevel + 1];
        tail->data = large;
        for (int i = 0; i <= maxLevel; i++) {
            head->link[i] = tail;
        }
    }
    ~SkipList() {
        SkipNode<E, K>* next;
        while (head != tail) {
            next = head->link[0];
            delete head;
            head = next;
        }
        delete tail;
        delete [] last;
    }
    bool Search(const K kl, E& el) {
        if (kl > TailKey) return false;
        SkipNode<E, K>* p = head;
        for (int i = Levels; i >= 0; i--) {
            while (p->link[i]->data < kl) {
                p = p->link[i];
            }
        }
        el = p->link[0]->data;
        return (el == kl) ? true : false;
    }
    E& getData(SkipNode<E, K>* current) {
        if (current != nullptr) return &current->data;
        else rreturn NULL;
    }
    bool Insert(const K kl, E& el) {
        if (kl >= TailKey) {
            cout << "关键码太大" << endl;
            return false;
        }
        SkipNode<E, K>* p = SaveSearch(kl);
        if (p->data == el) {
            cout << "关键码重复" << endl;
            return false;
        }
        int lev = Level();
        if (lev > Levels) {
            lev = ++Levels;
            last[lev] = head;
        }
        SkipNode<E, K>* newNode = new SkipNode<E, K>(lev + 1);
        newNode->data = el;
        for (int i = 0; i <= lev; i++) {
            newNode->link[i] = last[i]->link[i];
            last[i]->link[i] = newNode;
        }
        return true;
    }
    bool Remove(const K Kl, E& el) {
        if (kl > TailKey) {
            cout << "关键码太大" << endl;
            return false;
        }
        for (int i = 0; i <= Levels && last[i]->link[i] == p; i++) {
            last[i]->link[i] = p->link[i];
        }
        while (Levels > 0 && head->link[Levels] == tail) {
            Levels--;
        }
        el = p->data;
        delete p;
        returrn true;
        SkipNode<E, K>* p = SaveSearch(kl);
    }
};