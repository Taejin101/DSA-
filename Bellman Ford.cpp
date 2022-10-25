// Bellman Ford Algorithm - single source shortest path and detect negative cycles 

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int inf = 1e9;
vector<pair<int, int>> g[N];
vector<int> dist(N, inf);

int main(){
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; ++i){
        int u, v, wt;
        cin >> u >> v >> wt;
        g[u].push_back({v, wt});
    }

    int src;
    cin >> src;

    dist[src] = 0;
    for(int i = 1; i <= n - 1; ++i){
        for(int i = 0; i < n; ++i){
            for(auto child: g[i]){
                if(dist[i] + child.second < dist[child.first]){
                    dist[child.first] = dist[i] +  child.second;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i){
        cout << dist[i] << " ";
    }
    cout << endl;

    int fl = 1;
    for(int i = 0; i < n && fl; ++i){
        for(auto child: g[i]){
            if(dist[i] + child.second < dist[child.first]){
                cout << "Negative cycle exists";
                fl = 0;
                break;
            }
        }
    }
}

// [0,1,5],[1,5,-3],[1,2,-2],[2,4,3],[3,2,6],[3,4,-2],[5,3,1] -> 0 5 3 3 1 2
// [0,1,1],[1,2,-1],[2,3,-1],[3,0,-1] -> Negative cycle exists