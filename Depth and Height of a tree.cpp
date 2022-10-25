// Depth and Height of a vertex

#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define REPI(i,a,b) for(int i = b - 1; i >= a; --i)
using namespace std;

const int N = 1e4 + 10;
vector<int> g[N];
vector<bool> vis(N, false);
int depth[N];
int height[N];

void dfs(int vertex)
{
    vis[vertex] = true;
    for(auto child: g[vertex])
    {
        if(vis[child] == true) continue;
        depth[child] += depth[vertex] + 1;
        dfs(child);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main()
{
    int no_of_vertex, edges; cin >> no_of_vertex >> edges;
    
    REP(i,0,edges)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    REP(i,1,no_of_vertex+1)
    {
        cout << "Depth " << i << ": " << depth[i] << "\n";
    }
    cout << "\n\n";
    REP(i,1,no_of_vertex+1)
    {
        cout << "Height " << i << ": " << height[i] << "\n";
    }
}