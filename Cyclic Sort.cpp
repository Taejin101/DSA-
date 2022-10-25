
// 3 5 2 1 4
// Max Swaps = (N-1)
// Number of iterations = (N-1) + (N) = (2N-1) ~= O(N)

#include <bits/stdc++.h>
using namespace std;

void cycleSort(vector<int> &a, int n){
    int i = 0;
    while(i < n){
        int index = a[i] - 1;
        if(index != i){
            swap(a[index], a[i]);
        }else{
            i++;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
    }

    cycleSort(arr, n);

    for(int ele: arr){
        cout << ele << " ";
    }
    cout << endl;
}

int main(){
    solve(); 
}