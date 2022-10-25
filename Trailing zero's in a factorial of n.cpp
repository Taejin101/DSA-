// leading zeros in a factorial 
// zero's are formed because of 10 and 10 is 5*2
// now since 5 is always lesser than 2 in a factorial
// we have to count number of 5 in a factorial

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=5;i<=n;i*=5){
        count+=n/i;
    }
    cout<<count<<endl;
}