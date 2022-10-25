// AVL TREE

#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define REPI(i,a,b) for(int i = b - 1; i >= a; --i)
using namespace std;

struct Node{
  int val;
  struct Node *left, *right;
  int height;  
};

struct Node* createNewNode(int val)
{
    struct Node *tmp = new struct Node();
    tmp->val = val;
    tmp->left = tmp->right = nullptr;
    tmp->height = 1;
    return tmp;
}

int getHeight(struct Node *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return (root->height);
}

int getBalanceFactor(struct Node *root)
{
    if(root == nullptr)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}

struct Node* leftRotation(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *t = y->left;
    
    y->left = x;
    x->right = t;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

struct Node* rightRotation(struct Node *x)
{
    struct Node *y = x->left;
    struct Node *t = y->right;
    
    y->right = x;
    x->left = t;
    
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    
    return y;
}

struct Node* insert(struct Node *root, int key)
{
    if(root == nullptr)
    {
        struct Node *t = createNewNode(key);
        return t;
    }
    if(key < root->val)
    {
        root->left = insert(root->left, key);
    }
    else if(root->val < key)
    {
        root->right = insert(root->right, key);
    }
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    int bf = getBalanceFactor(root);
    if(bf > 1 )
    {
        if(key < root->left->val)
        {
            root = rightRotation(root);
        }
        else
        {
            root->left = leftRotation(root->left);
            root = rightRotation(root);
        }
    }
    if(bf < -1 )
    {
        if(key > root->right->val)
        {
            root = leftRotation(root);
        }
        else
        {
            root->right = rightRotation(root->right);
            root = leftRotation(root);
        }
    }
    
    return root;
}

void preorder(struct Node *root)
{
    if(root == nullptr) return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    struct Node * root = nullptr;
    
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    
    preorder(root);
}