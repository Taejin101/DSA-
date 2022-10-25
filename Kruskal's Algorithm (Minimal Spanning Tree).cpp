// Kruskal's Algorithm - Minimal Spanning Tree

#include <bits/stdc++.h>
using namespace std;

const int N=1e3+10;
int parent[N];
int size[N];

void make(int v){
	parent[v]=v;
	size[v]=1;
}

int find(int v){
	if(parent[v]==v)
		return v;
	return parent[v]=find(parent[v]);  // path compression
}

void Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u==v)
		return;
	if(size[u]<size[v])					// union by size
		swap(u,v);
	parent[v]=u;
	size[u]+=size[v];
}

int main(){
	int n,m;
	cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	
	for(int i=1;i<=n;++i){
		make(i);
	}
	
	for(int i=0;i<m;++i){
		int wt,u,v;
		cin>>u>>v>>wt;
		edges.push_back({wt,{u,v}});
	}
	sort(edges.begin(),edges.end());
	int total_wt=0;
	
	for(auto edge:edges){
		int wt=edge.first;
		int u=edge.second.first;
		int v=edge.second.second;
		if(find(u)==find(v))
			continue;
		Union(u,v);
		cout<<u<<" "<<v<<endl;
		total_wt+=wt;
	}
	cout<<total_wt<<endl;
}
