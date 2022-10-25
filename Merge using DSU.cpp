//Merge using DSU

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
int size[N];
multiset<int> sizes;

void make(int v){
	parent[v]=v;
	size[v]=1;
	sizes.insert(1);
}

int find(int v){
	if(parent[v]==v)
		return v;
	return (parent[v]=find(parent[v]));
}

void merge(int u,int v){
	sizes.erase(sizes.find(size[u]));
	sizes.erase(sizes.find(size[v]));
	
	sizes.insert(size[u]+size[v]);
}

void Union(int u,int v){
	u=find(u);
	v=find(v);
	if(u!=v){
		if(size[u]<size[v])
			swap(u,v);
		parent[v]=u;
		merge(u,v);
		size[u]+=size[v];
	}
}

int main(){
	int n,q;
	cin>>n>>q;
	
	for(int i=1;i<=n;++i){
		make(i);
	}
	
	while(q--){
		int u,v;
		cin>>u>>v;
		
		Union(u,v);
		if(sizes.size()==1)
			cout<<0<<endl;
		else{
			int mn=*(sizes.begin());
			int mx=*(--sizes.end());
			cout<<(mx-mn)<<endl;
		}
	}
}
