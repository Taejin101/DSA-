
// Kosaraju Algorithm

#include <bits/stdc++.h>
#define ll long long
#define REP(i,a,b) for(int i = a; i < b; ++i)
#define REPI(i,a,b) for(int i = b - 1; i >= a; --i)
using namespace std;

const int N = 0;


void topo_sort(vector<int> g[], int v, vector<bool> &vis, stack<int> &sorted)
{
    vis[v] = true;
    for(int child: g[v])
    {
        if(vis[child] == true) continue;
        topo_sort(g, child, vis, sorted);
    }
    sorted.push(v);
}

void dfs(int v, vector<bool> &vis, vector<int> g[])
{
    vis[v] = true;
    for(int child: g[v])
    {
        if(vis[child] == true) continue;
        dfs(child, vis, g);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n+1];
    for(int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    
    vector<bool> vis(n+1, false);
    stack<int> sorted;
    for(int i = 0; i < n; ++i)
    {
        if(vis[i] == true) continue;
        topo_sort(g, i, vis, sorted);
    }
    
    vector<int> transpose[n+1];
    for(int i = 0; i < n; ++i)
    {
        vis[i] = false;
        for(int child: g[i])
        {
            transpose[child].push_back(i);
        }
    }
    
    int cnt = 0;
    while(!sorted.empty())
    {
        int v = sorted.top();
        sorted.pop();
        if(vis[v] == false)
        {
            cnt++;
            dfs(v, vis, transpose);
        }
    }
    
    cout << "Connected Components: " << cnt << endl;
}