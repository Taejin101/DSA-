// Jump Search

#include <bits/stdc++.h>
using namespace std;

int jump_search(int a[], int n, int x){
    int m=sqrt(n);
    int prev=0,i=0;
    while(a[min(i,n)-1]<x){
        prev=i;
        i+=m;
        if(prev>=n)
            return -1;
    }
    
}

int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<half_adder(a,b);
}