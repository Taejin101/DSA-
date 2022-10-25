// bridges in a graph

#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
vector<int> g[N];
vector<bool> vis(N, false);

void dfs(int v, int parent, int &timer, vector<int> &disc, vector<int> &low, vector<vector<int>> &res){
    disc[v] = low[v] = timer++;
    vis[v] = true;
    for(int child: g[v]){
        if(child == parent) continue;
        if(vis[child]){
            // back edge
            low[v] = min(low[v], disc[child]);
        }else{
            dfs(child, v, timer, disc, low, res);
            low[v] = min(low[v], low[child]);
            if(low[child] > disc[v]){
                vector<int> ans;
                ans.push_back(v);
                ans.push_back(child);
                res.push_back(ans);
            }
        }
    }
}


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<int> disc(N, -1);
    vector<int> low(N, -1);
    int timer = 0;
    vector<vector<int>> res;
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs(i, -1, timer, disc, low, res);
        }
    }
}