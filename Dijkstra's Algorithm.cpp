// Dijkstra's Algorithm to find single source shortest distance (non-negative graphs only)

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int inf = 1e9 + 10;
vector<pair<int, int>> g[N];
vector<int> dist(N, inf);

void dijkstra(vector<pair<int, int>> g[]){
    set<pair<int, int>> st;
    dist[1] = 0;
    st.insert({dist[1], 1});
    while(st.size() > 0){
        auto pr = *st.begin();
        int v = pr.second;
        st.erase(st.begin());
        for(auto child: g[v]){
            int child_v = child.first;
            int child_wt = child.second;
            if(dist[v] + child_wt < dist[child_v]){
                dist[child_v] = dist[v] + child_wt;
                st.insert({dist[child_v], child_v});
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    dijkstra(g);

    for(int i = 1; i <= n; ++i){
        cout << dist[i] << " ";
    }
}
