#include <iostream>
#include <assert.h>
#include <stdlib.h>

template <class T>
struct Items {
    int utype;

    union {
        int ref;
        T value;
        GenListNode<T> * link;
    } info;

    Items() {
        utype = 0;
        info.ref = 0;
    }

    Items(Items<T>& RL) {
        utype = RL.utype;
        info = RL.info;
    }
};


template <class T>
struct GenListNode {
private:
    int utype;
    GenListNode<T>* tlink;
    union {
        int ref;
        T value;
        GenListNode<T>* hlink;
    } info;

public:
    GenListNode() {
        utype = 0;
        tlink = nullptr;
        info.ref = 0;
    }

    GenListNode(GenListNode<T>& RL) {
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }    
};


template <class T>
class GenList {
private:
    GenListNode<T>* first;
    GenListNode<T>* Copy(GenListNode<T>* ls) {
        GenListNode<T>* q = NULL;
        if (ls != NULL) {
            q = new GenListNode<T>;
            q->utype = ls->utype;
            switch (ls->utype) {
            case 0:
                q->info.ref = ls->info.ref;
                break;
            case 1:
                q->info.value = ls->info.value;
                break;
            case 2:
                q->info.hlink = Copy(ls->info.hlink);
                break;
            }
            q->tlink = Copy(ls->tlink);
        }
        return q;
    };
    int Length(GenListNode<T>* ls) {
        if (ls != NULL) {
            return 1 + Length(ls->tlink);
        } else {
            return 0;
        }
    };
    int depth(GenListNode<T>* ls) {
        if (ls->tlink == NULL) {
            return 1;
        }
        GenListNode<T>* temp = ls->tlink;
        int m = 0;
        int n;
        while (temp != NULL) {
            if (temp->utype == 2) {
                n = depth(temp->info.hlink);
                if (m < n) m = n;
            }
            temp = temp->tlink;
        }
        return m + 1;
    };
    bool equal(GenListNode<T>* s, GenListNode<T>* t) {
        int x;
        if (s->tlink == NULL && t->tlink == NULL) {
            return true;
        }
        if (s->tlink != NULL && t->tlink != NULL && s->tlink->utype == t->tlink->utype) {
            if (s->tlink->utype == 1) {
                x = (s->tlink->info.value == t->tlink->info.value)
            }
        }
    };
    void Remove(GenListNode<T>* ls);

public:
    GenList() {
        first = new GenListNode;
        assert(first != NULL);
    };

    ~GenList() {};
    bool Head(Items& x) {
        if (first->tlink == NULL) {
            return false;
        } else {
            x.utype = first->tlink->utype;
            x.info = first->tlink->info;
            return true;
        }
    };

    bool Tail(GenList<T>& lt) {
        if (first->tlink == NULL) {
            return false;
        } else {
            lt.first->utype = 0;
            lt.first->info.ref = 0;
            lt.first->tlink = Copy(first->tlink->tlink);
            return true;
        }
    };

    GenListNode<T>* First() {
        if (first->tlink == NULL) {
            return NULL;
        } else {
            return first->tlink;
        }
    };

    GenListNode<T>* Next(GenListNode<T>* elem) {
        if (elem->tlink == NULL) return NULL;
        else return elem->tlink;
    };

    void Copy(const GenList<T>& R) {
        first = Copy(R.first);
    };
    
    int Length() {
        return Length(first);
    };

    int depth() {
        return depth(first);
    };
};
