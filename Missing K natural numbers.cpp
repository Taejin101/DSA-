/* Sum of first K natural numbers missing in given Array */
#include <bits/stdc++.h>
using namespace std;

long long sumN(int n){
    return (n*(n+1)/2);
}

void printKMissingSum(vector<int> &v,int n,int k){
    int a=0,b=0,prev=0,cnt;
    long long ans=0;
    set<int> st(v.begin(),v.end());

    for(auto itr=st.begin();itr!=st.end()&&k>0;itr++){
        b=*itr;
        if(b<0){
            a=0;
            prev=0;
            continue;
        }
        a=prev;
        cnt=b-a-1;
        if(cnt<=k){
            ans+=(sumN(b-1)-sumN(a));
            k-=cnt;
        }else{
            ans+=(sumN(a+k)-sumN(a));
            k-=k;
        }
        prev=b;
    }
    if(k>0){
        ans+=(sumN(prev+k)-sumN(prev));
    }
    cout<<ans<<"\n";
}

int main(){
    vector<int> a={-2, -3, 4};
    int k=2;
    int n=3;

    printKMissingSum(a,n,k);
}