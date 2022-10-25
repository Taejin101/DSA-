// Matrix Exponentiation and fibonacci number

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix_multiply(vector<vector<int>> &a, vector<vector<int>> &b){
    int n = a.size();
    vector<vector<int>> ans(n, vector<int> (n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            for(int k = 0; k < n; ++k){
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}

vector<vector<int>> matrix_exp(vector<vector<int>> &a, int b){
    vector<vector<int>> ans = {{1, 0},{0, 1}};
    while(b > 0){
        if(b & 1){
            ans = matrix_multiply(ans, a);
        }
        a = matrix_multiply(a, a);
        b >>= 1;
    }
    return ans;
}

int main(){
    vector<vector<int>> a = {{1,1},{1,0}};
    int n; cin >> n;
    vector<vector<int>> ans = matrix_exp(a, n);
    cout << ans[0][1] << endl;
}