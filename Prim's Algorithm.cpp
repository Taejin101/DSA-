// Prim's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];
int key[N];
bool mst[N];
int parent[N];

int main(){
    for(int i = 0; i < N; ++i){
        key[i] = INF;
        parent[i] = -1;
        mst[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
        g[v].push_back({u, wt});
    }

    set<pair<int, int>> st;
    st.insert({key[0], 0});

    while(st.size() > 0){
        auto pr = *st.begin();
        st.erase(st.begin());
        int u = pr.second;
        mst[u] = true;

        for(auto child: g[u]){
            int v = child.first;
            int wt = child.second;
            if(mst[v] == false && wt < key[v]){
                key[v] = wt;
                parent[v] = u;
                st.insert({key[v], v});
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << parent[i] << " ";
    }
}