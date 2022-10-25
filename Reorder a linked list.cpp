// Reorder a linked list

// A1->A2->A3->A4->A5
// A1->A5->A2->A4->A3

#include <bits/stdc++.h>
using namespace std;


Node* reverse(Node *curr){
    Node *next = NULL, *prev = NULL;
    while(next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void reorder(Node *root){
    int n = 0;
    Node *ptr = root;
    while(ptr!=NULL){
        n++;
        ptr = ptr->next;
    } 
    
    ptr = root;
    for(int i = 0; i < n/2; ++i){
        ptr = ptr->next;
    }
    
    Node* h2 = reverse(ptr);
    Node *h1 = root, *ptr = h1;
    while(h1 != h2){
        h1 = h1->next;
        ptr->next = h2;
        ptr = ptr->next;
        swap(h1, h2);
    }
    ptr->next == NULL;
    return root;
}

int main(){
    
}