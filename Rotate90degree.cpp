#include <bits/stdc++.h>
using namespace std;


// Creating another 2D matrix
vector<vector<int> > rotate90degree(vector<vector<int> > &grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int> > ans(n, vector<int> (m)); 
    for(int j = 0, p = 0; j < m; j++, p++){
        for(int i = n-1, q = 0; i >= 0; i--, q++){
            ans[p][q] = grid[i][j];
        }
    } 
    return ans;
}

void print(vector<vector<int> > &ans){
    for(auto v: ans){
        for(int ele: v){
            cout << ele << " ";
        }
        cout << endl;
    }
}

void solve(){
    vector<vector<int> > grid = {{1,2,3},{4,5,6},{7,8,9}};
    int n = grid.size(), m = grid[0].size();
    // transpose of a matrix
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < m; ++j){
            swap(grid[i][j], grid[j][i]);
        }
    }
    // inplace solution
    for(int i = 0; i < n; ++i){
        reverse(grid[i].begin(), grid[i].end());
    }
    print(grid);
}

int main(){
    solve();
}