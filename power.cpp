// Calculate a raise to the power b in O(log n)

#include <bits/stdc++.h>
using namespace std;

int power(int a,int b){
    if(b==0) return 1;
    int temp=power(a,b/2);
    temp*=temp;
    if(b%2==0)
        return temp;
    else
        return a*temp;
}

int main(){
    cout<<power(2,10);
}