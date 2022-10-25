// Print boundaries of a binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
}

bool isleaf(Node *root){
    return (root->left == NULL && root->right == NULL);
}

void addLeaves(Node *root, vector<int> &ans){
    if(root == NULL) return;
    if(isleaf(root)) ans.push_back(root);
    
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addLeftBound(Node *root, vector<int> &ans){
    if(root == NULL) return;
    root=root->left;
    while(root){
        if(!isleaf(root)) ans.push_back(root->data);
        if(root->left) root = root->left;
        else root = root->right;
    }
}

void addRightBound(Node *root, vector<int> &ans){
    if(root == NULL) return;
    root = root->right;
    stack<int> st;
    while(root){
        if(!isleaf(root)) st.push(root);
        if(root->right) root = root->right;
        else root->left;
    }
    
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}

vector<int> boundary(Node *root){
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isleaf(root)) ans.push_back(root->data);
    addLeftBound(root, ans);
    addLeaves(root, ans);
    addRightBound(root, ans);
    
    return ans;
}

int main(){
    
}