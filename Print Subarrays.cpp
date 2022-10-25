/* Find Subarray ranges having difference between max and min exactly K */

#include <bits/stdc++.h>
using namespace std;

void printRanges(int a[],int n,int k){
    int f=1;
    for(int i=0;i<n;++i){
        set<int> sbset;
        for(int j=i;j<n;++j){
            sbset.insert(a[j]);
            int mx=*sbset.rbegin();
            int mn=*sbset.begin();
            if(mx-mn==k){
                cout<<(i+1)<<" "<<(j+1)<<"\n";
                f=0;
            }
        }
    }
    if(f==1){
        cout<<"-1\n";
    }
}

int main(){
    int a[]={5, 3, 4, 6, 1, 2};
    int n=6;
    int k=6;
    printRanges(a,n,k);
}