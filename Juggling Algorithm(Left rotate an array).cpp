// Juggling Algorithm

#include <bits/stdc++.h>
using namespace std;

void left_rotate(int a[],int n,int d){
    d=d%n;
    int gcd=__gcd(n,d);
    for(int i=0;i<gcd;++i){
        int temp=a[i];
        int j=i;
        while(1){
            int k=j+d;
            if(k>=n){
                k=k%n;
            }
            if(k==i){
                break;
            }
            a[j]=a[k];
            j=k;
        }
        a[j]=temp;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9,10,11,12};
    int d=3,n=12;
    left_rotate(arr,n,d);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}