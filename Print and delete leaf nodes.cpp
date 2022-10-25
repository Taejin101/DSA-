#include <bits/stdc++.h>
using namespace std;

map <int,vector<int>> leaf;

struct node{
    int data;
    struct node *left,*right;
};

int find_depth(struct node *root){
    if(root==NULL)
        return 0;
    int left_subtreedepth=find_depth(root->left);
    int right_subtreedepth=find_depth(root->right);
    int depth=max(left_subtreedepth,right_subtreedepth)+1;
    leaf[depth].push_back(root->data);
    return depth;
}

void print_leafnodes(struct node *root){
    if(root==NULL) return;
    int mx_depth=find_depth(root);

    for(auto it:leaf){
        vector<int> &leaf_nodes=it.second;
        for(auto ele:leaf_nodes){
            cout<<ele<<" ";
        }
        cout<<"\n";
    }
}

struct node* create_node(int d){
    struct node *tmp=new struct node();
    tmp->data=d;
    tmp->left=NULL;
    tmp->right=NULL;
    return tmp;
}

int main(){
    node* root = create_node(1);
    root->left = create_node(2);
    root->right = create_node(3);
    root->left->left = create_node(4);
    root->left->right = create_node(5);

    print_leafnodes(root);
}