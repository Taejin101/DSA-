// Trie data structure - insert, delete and display

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
        int index = key[i]-'a';
        if(ptr->children[index] == nullptr)
            ptr->children[index] = createTrie();
        ptr = ptr->children[index];
    }
    ptr->isLeaf = true;
}

bool search(TrieNode *root, string key){
    TrieNode *ptr = root;
    for(int i = 0; i < key.size(); ++i){
        int index = key[i] - 'a';
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
            s.push_back(i+'a');
            display(root->children[i], s);
            s.pop_back();
        }
    }
}

int main(){
    TrieNode *root = new TrieNode();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "neha");
    insert(root, "ishan");
    insert(root, "zebra");
    string s = "";
    display(root, s);
    
}