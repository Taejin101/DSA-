#include <bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int i=low-1;
    int j=low;
    int pivot=arr[high];
    while(j<=high-1){
        if(arr[j]<=pivot){
            i++;
            if(i!=j)
                swap(arr[i],arr[j]);
        }
        j++;
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick(int arr[],int low,int high){
    if(low<high){
        int p=partition(arr,low,high);

        quick(arr, low, p-1);
        quick(arr, p+1, high);
    }
}

int main(){
    int arr[]={10, 9, 11, 6, 15, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick(arr,0,n-1);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}