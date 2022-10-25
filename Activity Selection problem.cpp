// Activity Selection Problem

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> time; 
    for(int i = 0; i < n; ++i){
        int start, end;
        cin >> start >> end;
        time.push_back({start, end});
    }

    sort(time.begin(), time.end(), [](vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    });

    // cout << time[0][0] << " " << time[0][1] << endl;
    count = 1;
    int end = time[0][1];
    for(int i = 1; i < n; ++i){
        if(end <= time[i][0]){
            // cout << time[i][0] << " " << time[i][1] << endl;
            count++;
            end = time[i][1];
        }
    }
}