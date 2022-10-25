#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
bool vis[N];

bool dfs(int vertex, int par){
	vis[vertex]=true;
	bool isCycleExists=false;
	for(auto child:g[vertex]){
		if(vis[child]&&child==par) continue;
		if(vis[child]) return true;
		isCycleExists|=dfs(child,vertex);
	}
	return isCycleExists;
}

int main(){
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;++i){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	bool isCycleExists=false;
	for(int i=1;i<=n;++i){
		if (vis[i]) continue;
		if(dfs(i,0)){
			isCycleExists=true;
			break;
		}
	}
	
	cout<<isCycleExists<<endl;
}
