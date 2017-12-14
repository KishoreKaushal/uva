#include<bits/stdc++.h>
using namespace std;

#define INORDER (0)
#define PREORDER (1)
#define POSTORDER (2)

template <typename Key>
class BinarySearchTree {
private:
    struct BinaryNode {
        Key element;     // The data in the node
        BinaryNode *left;   // left child
        BinaryNode *right;  // right child
        BinaryNode *parent; // parent of this node

        BinaryNode(const Key & theElement, BinaryNode *lt, BinaryNode *rt , BinaryNode *p)
        : element{theElement}, left{lt}, right{rt}, parent{p} {}

        BinaryNode(Key && theElement , BinaryNode *lt, BinaryNode *rt, BinaryNode *p)
        : element{std::move (theElement)} , left{lt}, right{rt}, parent{p} {}
    } ;
    BinaryNode *root;

    void inOrderTreeWalk(BinaryNode* x = nullptr , ostream & out = cout) const;
    void preOrderTreeWalk(BinaryNode* x = nullptr, ostream & out = cout) const;
    void postOrderTreeWalk(BinaryNode* x = nullptr, ostream & out = cout) const;

    void transplant(BinaryNode *u, BinaryNode *v);

public:
    ~BinarySearchTree(){
        clear(root);
    }

    void printTree(ostream & out = cout  , int type = INORDER) const;

    BinaryNode* treeSearch(const Key &k , BinaryNode *x) const;
    int height(BinaryNode *t );

    BinaryNode* findMin(BinaryNode *x = nullptr) const;
    BinaryNode* findMax(BinaryNode *x = nullptr) const;
    BinaryNode* succesor(BinaryNode *x = nullptr) const;
    BinaryNode* predecessor(BinaryNode *x = nullptr) const;

    void remove(BinaryNode *z);
    void insert(const Key &k);
    bool contains(const Key &k ) const;
    bool isEmpty() const;
    void clear(BinaryNode *x=nullptr);
};

template <typename Key>
void BinarySearchTree<Key>::clear(BinaryNode *x){
    if(x==nullptr)  x = root;
    clear(x->left);
    clear(x->right);
    delete x;
}

template <typename Key>
void BinarySearchTree<Key>::transplant(BinaryNode *u, BinaryNode *v) {
    if(u->parent == nullptr) {
        root = v;
    } else if(u == u->parent->left) {
        u->parent->left = v;
    } else u->parent->right = v;
    if(v!= nullptr) v->parent = u->parent;
}

template <typename Key>
void BinarySearchTree<Key>::remove(BinaryNode *z) {
    // assuming z is in the tree
    if(z==nullptr || !contains(z->element))   return ;
    if(z->left == nullptr)  transplant(z , z->right);
    else if(z->right == nullptr) transplant(z , z->left);
    else {
        BinaryNode* y = findMin(z->right);
        if(y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        transplant(z , y);
        y->left = z->left;
        y->left->parent = y;
    }
    delete z;
}

template <typename Key>
bool BinarySearchTree<Key>::isEmpty() const {
    return (root == nullptr);
}


template <typename Key>
bool BinarySearchTree<Key>::contains(const Key &k) const {
    BinaryNode* x = root;
    while(x!=nullptr) {
        if(k < x->element) x =  x->left;
        else if(k > x->element) x = x->right;
        else return true;   // match
    }
    return false;
}

template <typename Key>
void BinarySearchTree<Key>::insert(const Key &k){
    BinaryNode* x = root;
    BinaryNode* z = new BinaryNode{k , nullptr , nullptr, nullptr};
    BinaryNode* y = nullptr;

    while(x!=nullptr) {
        y = x;
        if(z->element < x->element) x = x->left;
        else x = x->right;
    }
    z->parent = y;
    if(y==nullptr)
        root = z;   // tree was empty
    else if(z->element < y->element)
        y->left = z;
    else y->right = z;
}

template <typename Key>
typename BinarySearchTree<Key>::BinaryNode* BinarySearchTree<Key>::predecessor(BinaryNode *x) const {
    if(x==nullptr) return nullptr;
    if(x->left != nullptr)  return findMax(x->left);
    BinaryNode* y = x->parent;
    while(y!=nullptr and x==y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

template <typename Key>
typename BinarySearchTree<Key>::BinaryNode* BinarySearchTree<Key>::succesor(BinaryNode *x) const {
    if(x==nullptr) return nullptr;
    if(x->right != nullptr) return findMin(x->right);
    BinaryNode* y = x->parent ;
    while(y!=nullptr and x==y->right) {
        x = y ;
        y = y->parent;
    }
    return y;
}

template <typename Key>
typename BinarySearchTree<Key>::BinaryNode* BinarySearchTree<Key>::findMin(BinaryNode *x) const {
    if(x!=nullptr)
        while(x->left != nullptr) {
            x = x->left;
        }
    return x;
}

template <typename Key>
typename BinarySearchTree<Key>::BinaryNode* BinarySearchTree<Key>::findMax(BinaryNode *x) const {
    if(x!=nullptr)
        while(x->right != nullptr) {
            x = x->right;
        }
    return x;
}

template <typename Key>
typename BinarySearchTree<Key>::BinaryNode* BinarySearchTree<Key>::treeSearch(const Key &k , BinaryNode *x) const {
    while(x!=nullptr and k!=x->key){
        if(k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}

template <typename Key>
void BinarySearchTree<Key>::printTree(ostream & out , int type) const {
    switch(type) {
        case INORDER : inOrderTreeWalk(root , out);
        case PREORDER : preOrderTreeWalk(root , out);
        case POSTORDER : postOrderTreeWalk(root ,out);
        default: inOrderTreeWalk(out);
    }
}

// print a sorted list of the elements in the binary search tree
template <typename Key>
void BinarySearchTree<Key>::inOrderTreeWalk(BinaryNode* x , ostream &out ) const {
    if(x!=nullptr) {
        inOrderTreeWalk(x->left);
        out<<x.element<<" ";
        inOrderTreeWalk(x->right);
    }
}

template <typename Key>
int BinarySearchTree<Key>::height(BinaryNode *t){
    if(t==nullptr) return -1;
    else return 1 + max(height(t->left) , height(t->right));
}
