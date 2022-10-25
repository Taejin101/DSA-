// Subtree sum

#include <bits/stdc++.h>
#define REP(i,a,b) for(int i = a; i < b; ++i)
using namespace std;

const int N = 1e4;
vector<int> g[N];
bool vis[N];
int subtree_sum[N];

void dfs(int vertex)
{
    subtree_sum[vertex] = vertex;
    vis[vertex] = true;
    for(auto child: g[vertex])
    {
        if(vis[child] == true) continue;
        dfs(child);
        subtree_sum[vertex] += subtree_sum[child];
    }
}

int main()
{ 
    int n, m; cin >> n >> m;
    REP(i,0,m)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1);
    
    REP(i,1,n+1)
    {
        cout << "Subtree sum " << i << ": " << subtree_sum[i] << "\n";
    }
    
    return 0;
}
