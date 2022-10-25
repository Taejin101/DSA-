// Fractional Knapsack Problem

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(Item a, Item b){
    double a_fraction = a.value / a.weight;
    double b_fraction = b.value / b.weight;

    return a_fraction > b_fraction;
}

double fractionalKnapsack(int W, Item a[], int n){
    sort(arr, arr + n, cmp);

    int cur_wt = 0, mx_value = 0;
    for(int i = 0; i < n; ++i){
        if(cur_wt + arr[i].weight <= W){
            cur_wt += arr[i].weight;
            mx_value += arr[i].value;
        }else{
            int rem_wt = W - cur_wt;
            mx_value += rem_wt * (arr[i].value / arr[i].weight);
            cur_wt += rem_wt;
            return mx_value;
        }
    }

    return mx_value;
}

int main(){
    int wt = 50;
    Item a[] = {{ 60, 10 }, { 100, 20 }, { 120, 30 }};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(wt, a, n);

    return 0;
}