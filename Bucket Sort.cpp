// Bucket Sort
#include <bits/stdc++.h>
using namespace std;

void bucket_sort(vector<float> &arr){
    int n=arr.size();
    vector<float> bucket[n];
    for(int i=0;i<n;++i){
        int ind=n*arr[i];
        bucket[ind].push_back(arr[i]);
    }
    for(int i=0;i<n;++i){
        sort(bucket[i].begin(),bucket[i].end());
    }
    int k=0;
    for(int i=0;i<n;++i){
        for(int j=0;j<bucket[i].size();++j){
            arr[k++]=bucket[i][j];
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<float> arr(n);
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    bucket_sort(arr);
    for(int i=0;i<n;++i){
        cout<<arr[i]<<endl;
    }
}