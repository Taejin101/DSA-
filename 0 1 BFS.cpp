// 0 1 - BFS

#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = INT_MAX;

vector<pair<int, int>> g[N];
vector<int> level(N, INF);
int n, m;

int bfs(){
    deque<int> dq;
    dq.push_back(1);
    level[1] = 0;

    while(!dq.empty()){
        int v = dq.front();
        dq.pop_front();

        for(auto &child: g[v]){
            int child_v = child.first;
            int wt = child.second;
            if(level[v] + wt < level[child_v]){
                level[child_v] = level[v] + wt;
                if(wt == 1){
                    dq.push_back(child_v);
                }else{
                    dq.push_front(child_v);
                }
            } 
        }
    }
    return level[n] == INF ? -1: level[n];
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        if(u == v) continue;
        g[u].push_back({v,0});
        g[v].push_back({u,1});
    }

    cout << bfs() << endl;
}