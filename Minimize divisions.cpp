/* Minimize divisions such that no Array element is divisible by K */

#include <bits/stdc++.h>
using namespace std;

int min_operation(int a[],int n,int k){
    set<int> st;
    for(int i=0;i<n;++i){
        while(a[i]%k==0){
            if(st.find(a[i])==st.end())
                st.insert(a[i]);
            a[i]/=k;
        }
    }
    return (int)st.size();
}

int main(){
    int a[]={3, 5, 8, 12, 4};
    int k=4;
    int n=5;
    cout<<min_operation(a,n,k);
}