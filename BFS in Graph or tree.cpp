// BFS
// Shortest distance of a node from a vertex is the level of the node which can be easily find with the help of bfs but only when edges have equal wt.

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;

void bfs(int source, vector<bool> &vis, vector<int> &level, vector<int> g[]){
	queue<int> q;
	q.push(source);
	
	while(!q.empty()){
		int c_vertex=q.front();
		q.pop();
		vis[c_vertex]=1;
		for(int child:g[c_vertex]){
			if(!vis[child]){
				q.push(child);
				vis[child]=1;
				level[child]+=level[c_vertex]+1;
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	
	for(int i=0;i<n-1;++i){
		int v1,v2;
		cin>>v1>>v2;
		g[v1].push_back(v2);
		g[v2].push_back(v1);
	}
	
	bfs(1);
	
	for(int i=1;i<=n;++i){
		cout<<i<<":"<<level[i]<<endl;
	}
}

// Time complexity O(V+E)
