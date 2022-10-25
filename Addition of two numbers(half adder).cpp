// addition of two numbers using half adder logic
// sum=a^b and carry=(a&b)<<1;

#include <bits/stdc++.h>
using namespace std;

int half_adder(int a,int b){
    while(b!=0){
        int sum=a^b;
        int carry=(a&b)<<1;
        a=sum;
        b=carry;
    }
    return a;
}

int main(){
    int a,b;
    cout<<"Enter two numbers: ";
    cin>>a>>b;
    cout<<half_adder(a,b);
}