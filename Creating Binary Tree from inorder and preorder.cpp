#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define REPI(i,a,b) for(int i = b - 1; i >= a; --i)
using namespace std;

 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

TreeNode* build(vector<int> &pre, int preStart, int preEnd,
 vector<int> &in, int inStart, int inEnd, map<int,int> &hsh)
{
    if(preEnd > preStart || inEnd > inStart) return nullptr;
    
    TreeNode* tmp = new TreeNode(pre[preStart]);
    
    int ind = hsh[pre[preStart]];
    int numsLeft = ind - inStart;
    tmp->left = build(pre, preStart+1, preStart+numsLeft,
        in, inStart, ind-1, hsh);
    tmp->right = build(pre, preStart+numsLeft+1, preEnd,
        in, ind+1, inEnd, hsh);
    
    return tmp;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> hsh;
        int n = inorder.size();
        for(int i = 0; i < n; ++i)
        {
            hsh[inorder[i]] = i;
        }
        
        TreeNode* root = build(preorder, 0, preorder.size()-1,
            0, inorder.size()-1,hsh);
        
        return root;
}       

int main()
{
    string s = "[1,2,3,null,null,4,5,6,7]";
    TreeNode *tmp = deserialize(s);
    cout << serialize(tmp);
    // level_order(tmp);
}