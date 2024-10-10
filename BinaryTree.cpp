#include <iostream>
#include <stdlib.h>
#include "stack.h"
template <class T>

struct BinTreeNode {
    T data;
    BinTreeNode<T>* leftChild; 
    BinTreeNode<T>* rightChild;
    BinTreeNode() {   // 无参数默认构造函数
        leftChild = nullptr;
        rightChild = nullptr;
    }
    BinTreeNode(T x, BinTreeNode<T>* l = nullptr, BinTreeNode<T>* r = nullptr) {   // 有传参数的构造函数
        data = x;
        leftChild(l);
        rightChild(r);
    }
};

template <class T>
class BinaryTree {
protected:
    BinTreeNode<T>* root;
    T RefValue;
    bool equal(BinTreeNode<T>* a, BinTreeNode<T>* b) {
        if (a == NULL && b == NULL) return true;
        if (a != NULL && b != NULL && a->data == b->data && equal(a->leftChild, b->rightChild) && equal(a->rightChild, b->rightChild)) return true;
        else return false;
    }
    void GYCreateBinTree(istream& in, BinTreeNode<T>*& BT) {
        Stack<BinTreeNode<char>*> s;
        BT = nullptr;
        BinTreeNode<char>* p;
        BinTreeNode<char>* t;
        int k;
        char ch;
        in >> ch;
        while (ch != RefValue) {
            switch (ch) {
            case '(':
                s.Push(p);
                k = 1;
                break;
            case ')':
                s.Pop(p);
                break;
            case ',':
                k = 2;
                break;
            default:
                p = new BinTreeNode(ch);
                if (BT == nullptr) {
                    BT = p;
                } else if (k == 1) {
                    s.getTop(t);
                    t->leftChild = p;
                } else {
                    s.getTop(t);
                    t->rightChild = p;
                }
            }
            in >> ch;
        }
    }
    void CreateBinTree(istream& in, BinTreeNode<T>*& subTree) {
        T item;
        if (! in.eof()) {
            in >> item;
            if (item != RefValue) {
                subTree = new BinTreeNode<T>(item);
                if (subTree == nullptr) {
                    cout << "存储分配错！" << endl;
                    exit(1);
                }
                CreateBinTree(in, subTree->leftChild);
                CreateBinTree(in, subTree->rightChild);
            }
            else subTree = nullptr;
        }
    }
    bool Insert(BinTreeNode<T>*& subTree, const T& x);
    void destroy(BinTreeNode<T>*& subTree) {
        if (subTree != nullptr) {
            destroy(subTree -> leftChild);
            destroy(subTree -> rightChild);
            delete subTree;
        }
    }
    bool Find(BinTreeNode<T>*& subTree, const T& x) const;
    BinTreeNode<T>* Copy(BinTreeNode<T>* orignode) {
        if (orignode == nullptr) return NULL;
        BinTreeNode<T>* temp = new BinTreeNode<T>;
        temp->data = orignode->data;
        temp->leftChild = Copy(orignode->leftChild);
        temp->rightChild = Copy(orignode->rightChild);
        return temp;
    }
    int Height(BinTreeNode<T>*& subTree) {
        if (subTree == NULL) return 0;
        else {
            int i = Height(subTree->leftChild);
            int j = Height(subTree->leftChild);
            return (i < j) ? j + 1 : i + 1;
        }
    }
    int Size(BinTreeNode<T>*& subTree) {
        if (subTree != nullptr) {
            return 0;
        } else {
            return 1 + Size(subTree->leftChild) + Size(subTree->rightChild);
        }
    }
    BinTreeNode<T>* Parent(BinTreeNode<T>*& subTree; BinTreeNode<T>*& current) {
        if (subTree == NULL) return NULL;
        if (subTree -> leftChild == current || subTree -> rightChild == current) {
            return subTree;
        }
        BinTreeNode<T>* p;
        if ((p = Parent(subTree -> leftChild, current) != NULL)) return p;
        else return Parent(subTree -> rightChild, current);
    }
    BinTreeNode<T>* Find(BinTreeNode<T>*& subTree; const T& x) const;
    void Traverse(BinTreeNode<T>*& subTree, ostream& out) {
        if (subTree != nullptr) {
            out << subTree -> data << ' ';
            Traverse(subTree -> leftChild, out);
            Traverse(subTree -> rightChild, out);
        }
    }
    void preOrder(BinTreeNode<T>& subTree, void (*visit)(BinTreeNode<T>* p)) {
        if (subTree != NULL) {
            visit(subTree);
            preOrder(subTree->leftChild, visit);
            preOrder(subTree->rightChild,visit);
        }
    }
    void inOrder(BinTreeNode<T>& subTree, void (*visit)(BinTreeNode<T>* p)) {
        if (subTree != NULL) {
            inOrder(subTree->leftChild, visit);
            visit(subTree);
            inOrder(subTree->rightChild, visit);
        }
    }
    void postOrder(BinTreeNode<T>& Tree, void (*visit)(BinTreeNode<T>* p)) {
        if (subTree != NULL) {
            postOrder(subTree->leftChild, visit);
            postOrder(subTree->rightChild, visit);
            visit(subTree);
        }        
    }
    friend istream& operator >> (istream& in, BinaryTree<T>& Tree) {
        CreateBinTree(in, Tree.root);
        return in;
    }
    friend ostream& operator >> (ostream& out, BinaryTree<T>& Tree) {
        out << "二叉树的前序遍历\n";
        Tree.Traverse(Tree.root, out);
        return out;
    }
    int operator == (const BinaryTree<T>& s, const BinaryTree<T>& t) {
        return (equal(s.root, t.root)) ? true : false;
    }
public:
    BinaryTree() {
        root = nullptr;
    }
    BinaryTree(T value) {
        RefValue = value;
        root = nullptr;
    }
    BinaryTree(BinaryTree<T>& s) {
        root  = Copy(s.root);
    }
    ~BinaryTree() {
        destroy(root);
    }
    bool IsEmpty() {
        return (root == NULL) ? true : false;
    }
    BinTreeNode<T>* Parent(BinTreeNode<T>* current) {
        return (root == nullptr || root == current) ? NULL : Parent(root, current);
    }
    BinTreeNode<T>* LeftChild(BinTreeNode<T>* current) {
        return (current != nullptr) ? current -> leftChild : NULL;
    }
    BinTreeNode<T>* RightChild(BinTreeNode<T>* current) {
        return (current != nullptr) ? current -> rightChild : NULL;
    }
    int Height() {
        return Height(root);
    }
    int Size() {
        return Size(root);
    }
    BinTreeNode<T>* getRoot() const {
        return root;
    }
    void preOrder(void (* visit)(BinTreeNode<T>* p)) {
        preOrder(root, visit);
    }
    void inOrder(void (* visit)(BinTreeNode<T>* p)) {
        inOrder(root, visit);
    }
    void postOrder(void (* visit)(BinTreeNode<T>* p)) {
        postOrder(root, visit);
    }
    void LevelOrder(void (* visit)(BinTreeNode<T>* p)) {}
    int Insert(const T item) {}
    BinTreeNode<T>* Find(T item) const {}
    void PrintBTree(BinTreeNode<T>* BT) {
        if (BT != NULL) {
            cout << BT->data;
            if (BT->leftChild != NULL || BT->rightChild != NULL) {
                cout << '(';
                PrintBTree(BT->leftChild);
                cout << ',';
                if (BT->rightChild != NULL) {
                    PrintBTree(BT->rightChild);
                }
                cout << ')';
            }
        }
    }
};