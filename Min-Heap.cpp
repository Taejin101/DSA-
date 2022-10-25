// Min-Heap

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int ind){
    int smallest = ind;
    int left = 2 * ind + 1;
    int right = 2 * ind + 2;
    if(left < n && arr[left] < arr[smallest]){
        smallest = left;
    }
    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }
    if(smallest != ind){
        swap(arr[ind], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

int extract_min(int a[], int &n){
    if(n < 1){
        return -1;
    }

    int mini = a[0];
    a[0] = a[n - 1];
    n--;
    heapify(a, n, 0);
    return mini;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = (n-1)/2; i >= 0; --i){
        heapify(a, n, i);
    }
    for(int i = 0; i < n; ++i){
        cout << extract_min(a, n) << " ";
    }
    
    return 0;
}