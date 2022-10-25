#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
}

void insertion_sort(int arr[], int n){
    for(int i=1;i<n;++i){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void selection_sort(int arr[], int n){
    for(int i=0;i<n;++i){
        int minIndex=i;
        for(int j=i+1;j<n;++j){
            if(arr[j]<arr[minIndex])
                minIndex=j;
        }
        if(minIndex!=i)
            swap(arr[minIndex],arr[i]);
    }
}

int main(){
    int arr[]={10, 9, 11, 6, 15, 2};
    int n=sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
}