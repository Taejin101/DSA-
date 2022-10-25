// Dijkstra's Algorithm

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+10;

int dijkstra(int src, int n, vector<pair<int,int> > g[]){
	vector<int> vis(N,0);
	vector<int> dist(N,INF);
	
	set<pair<int,int>> st;
	dist[src]=0;
	st.insert(dist[src],src);
		
	while(st.size()>0){
		auto pr=*st.begin();
		int v_wt=pr.first;
		int v=pr.second;
		
		st.erase(st.begin());
		if(vis[v]) continue;
		vis[v]=1;
		
		for(auto child:g[v]){
			int child_v=child.first;
			int child_wt=child.second;
			
			if(dist[v]+child_wt<dist[child_v]){
				dist[child_v]=dist[v]+child_wt;
				st.insert({dist[child_v],child_v});
			}
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;++i){
		if(dist[i]==INF) return -1;
		ans=max(ans,dist[i]);
	}
	return ans;
}

int networkDelayTime(vector<vector<int>>& times, int n, int k){
    vector<pair<int,int>> g[N];
    for(auto vect:times){
    	g[vect[0]].push_back({vect[1],vect[2]});
	}
	
	return dijkstra(k,n,g);
}

int main(){
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<m;++i){
		int x,y,wt;
		cin>>x>>y>>wt;
		
		g[x].push_back({y,wt});
	}
}
