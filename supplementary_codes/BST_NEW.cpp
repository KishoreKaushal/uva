#include<bits/stdc++.h>

template <class Key>
struct BinaryNode  {
    Key element;
    BinaryNode* parent;
    BinaryNode* right;
    BinaryNode* left;
    BinaryNode(const Key & theElement, BinaryNode *lt, BinaryNode *rt , BinaryNode *p)
    : element{theElement}, left{lt}, right{rt}, parent{p} {}
};


template <class Key>
class BinarySearchTree {
public:
    BinarySearchTree();
    ~BinarySearchTree();

    BinaryNode<Key> *root;
    void transplant(BinaryNode<Key> *u, BinaryNode<Key> *v);

    BinaryNode<Key>* findMin(BinaryNode<Key> *x ) const;
    BinaryNode* findMax(BinaryNode *x ) const;
    BinaryNode* succesor(BinaryNode *x ) const;
    BinaryNode* predecessor(BinaryNode *x ) const;

    void remove(BinaryNode *z);
    void insert(const Key &k, BinaryNode* x);
    bool contains(const Key &k , BinaryNode *x) const;
    bool isEmpty() const;
    void clear(BinaryNode *x);
};
