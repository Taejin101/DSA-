// Given a dictionary, a method to do lookup in dictionary 
// and a M x N board where every cell has one character. Find 
// all possible words that can be formed by a sequence of adjacent 
// characters. Note that we can move to any of 8 adjacent characters, 
// but a word should not have multiple instances of same cell.

#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];
    bool isLeaf;
};

TrieNode* createTrie(){
    TrieNode* ptr = new TrieNode();
    ptr->isLeaf = false;
    for(int i = 0; i < ALPHABET_SIZE; ++i)
        ptr->children[i] = nullptr;
    return ptr;
}


void insert(TrieNode *root, string key){
    TrieNode* ptr = root;
    for(int i = 0; i < key.size(); ++i){
        int index = key[i]-'A';
        if(ptr->children[index] == nullptr)
            ptr->children[index] = createTrie();
        ptr = ptr->children[index];
    }
    ptr->isLeaf = true;
}

bool search(TrieNode *root, string key){
    TrieNode *ptr = root;
    for(int i = 0; i < key.size(); ++i){
        int index = key[i] - 'A';
        if(ptr->children[index] == nullptr) return false;
        ptr = ptr->children[index];
    }
    return ptr->isLeaf;
}

void display(TrieNode* root, string &s){
    if(root->isLeaf){
        cout << s << endl;
    }
    for(int i = 0; i < ALPHABET_SIZE; ++i){
        if(root->children[i] != nullptr){
            s.push_back(i+'A');
            display(root->children[i], s);
            s.pop_back();
        }
    }
}

bool isValid(int i, int j, int m, int n){
    return (i>=0 && j>=0 && i<m && j<n);
}

vector<pair<int,int> > movements = {
        {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 1}   
};

void dfs(int i, int j, vector<vector<char> > &grid, TrieNode* root, map<string, bool> &isPresent, vector<vector<bool> > &vis, string &s){
    if(!isValid(i, j, grid.size(), grid[0].size()) || vis[i][j] == true){
        return;
    }
    if(root->isLeaf){
        isPresent[s] = 1;
    }
    char ch = grid[i][j];
    if(root->children[ch - 'A'] == nullptr) return;
    vis[i][j] = true;
    s.push_back(ch);
    for(auto &movement: movements){
        int x = i+movement.first, y = j+movement.second;
        dfs(x, y, grid, root->children[ch-'A'], isPresent, vis, s);
    }
    vis[i][j] = false;
    s.pop_back();
}

void findWords(vector<vector<char> > &grid, TrieNode* root, map<string, bool> &isPresent){
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool> > vis(m, vector<bool> (n, false));
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            string s = "";
            dfs(i, j, grid, root, isPresent, vis, s);
        }
    }
}

int main(){
    vector<string> v = {"GEEKS", "FOR", "QUIZ", "GO"};
    TrieNode *root = createTrie();
    for(string &s: v){
        insert(root, s);
    }
    vector<vector<char> > grid = {
                {'G', 'I', 'Z'},
                {'U', 'E', 'K'},
                {'Q', 'S', 'E'}
            };
    map<string, bool> isPresent;
    findWords(grid, root, isPresent);
    for(auto &it: isPresent){
        cout << it.first << " ";
    }
}