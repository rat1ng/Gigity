const int DefaultSize = 100;
enum KindOfStatus {Active, Empty, Deleted};

template <class E, class K>
class HashTable {
private:
    int divitor;
    int CurrentSize, TableSize;
    E * ht;
    KindOfStatus* info;
    int FindPos(const K kl) const { //搜索到k返回k位置，没搜到k能放就放然后返回放好位置，放不了返回“就这样”的位置
        int i = kl % divitor;
        int j = i;
        do {
            if (info[j] == empty || info[j] == Active && ht[j] == kl) return j;
            j = (j + 1) % TableSize;
        } while (j != i);
        return j;
    }
    int operator == (E& el) {
        return *this == el;
    }
    int operator != (E& el) {
        return *this != el;
    }
public:
    HashTable(const int d, int sz = DefaultSize) {
        divitor  = d;
        TableSize = sz;
        CurrentSize = 0;
        ht = new E[TableSize];
        info = new KindOfStatus[TableSize];
        for (int i = 0; i < TableSize; i++) {
            info[i] = empty;
        }
    }
    ~HashTable() {
        delete [] ht;
        delete [] info;
    }
    HashTable<E, K>& operator = (const HashTable<E, K>& ht2) {
        if (this != &ht2) {
            delete [] ht;
            delete [] info;
            TableSize = ht2.TableSize;
            ht = new E[TableSize];
            info = new KindOfStatus[TableSize];
            for (int i = 0; i < TableSize; i++) {
                ht[i] = ht2.ht[i];
                info[i] = ht2.info[i];
            }
            CurrentSize = ht2.CurrentSize;
        }
        return *this;
    }
    bool Search(const K kl, E& el) const { //找得到就el带走kl值，找不到就false
        int i = FindPos(kl)
        if (info[i] != Active || ht[i] != kl) return false;
        el = ht[i];
        return true;
    }
    bool Insert(const E& el) {
        K kl = el;
        int i = FindPos(kl);
        if (info[i] != Active) {
            ht[i] = el;
            info[i] = Active;
            CurrentSize++;
            return true;
        }
        if (info[i] == Active && ht[i] == el) {
            cout << "表中已有此元素，不能插入" << endl;
            return false;
        }
        cout << "表已满，不能插入" << endl;
        return false;
    }
    bool Remove(const K kl, E& el) {
        int i = FindPos(kl);
        if (info[i] == Active) {
            info[i] = Deleted;
            CurrentSize--;
            return true;
        }
        else return false;
    }
    void makeEmpty() { //将info全部置空即代表全表可写
        for (int  = 0; i < TableSize; i++) info[i] = Empty;
        CurrentSize = 0;
    }
};