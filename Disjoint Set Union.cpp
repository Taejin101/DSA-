// Disjoint Set Union

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int parent[N];
int size[N];

class DSU{
	public:
		void make(int v){
			parent[v]=v;
			size[v]=1;
		}
		
		int find(int v){
			if(parent[v]==v)
				return v;
			// Path Compression
			return parent[v]=find(parent[v]);
		}
		
		void Union(int a,int b){
			a=find(a);
			b=find(b);
			
			if(a!=b){
				// Union by size or rank
				if(size[a]<size[b])
					swap(a,b);
				parent[b]=a;
				size[a]+=size[b];
			}
		}
};

int main(){
	int n,k;
	cin>>n>>k;
	
	DSU dsu;
	
	for(int i=1;i<=n;++i){
		dsu.make(i);
	}
	
	while(k--){
		int u,v;
		cin>>u>>v;
		dsu.Union(u,v);
	}
	
	int cnncted_cmp=0;
	for(int i=1;i<n;++i){
		if(i==dsu.find(i))
			cnncted_cmp++;
	}
	
	cout<<cnncted_cmp<<endl;
}
