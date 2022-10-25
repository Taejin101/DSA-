// Merge two sorted linked lists


#include <bits/stdc++.h>
using namespace std;



 // * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if(list1 == nullptr) return list2;
    if(list2 == nullptr) return list1;
    
    ListNode *l1 = list1, *l2 = list2, *tmp = nullptr;
    if(list1->val > list2->val){
        l1 = list2;
        l2 = list1;
    }
    
    ListNode *res = l1;
    while(l1 != nullptr){
        while(l1 && l2 && l1->val <= l2->val){
            tmp = l1;
            l1 = l1->next;
        }
        tmp->next = l2;
        swap(l1, l2);
    }
    tmp->next = l2;
    return res;
}
int main(){
    
}