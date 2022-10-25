// Deletion of one edge such that the product of two subtrees is maximum

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int> g[N];
int val[N];
int subtree_sum[N];


void dfs(int vertex, int p=-1){
	subtree_sum[vertex]+=val[vertex-1];
	for(auto child:g[vertex]){
		if(child==p) continue;
		dfs(child,vertex);
		subtree_sum[vertex]+=subtree_sum[child];
	}
}

vector<int> path(int v){
	vector<int> ans;
	while(v!=-1){
		ans.push_back(v);
		v=par[v];
	}
	reverse(ans.begin(),ans.end());
	return ans;
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
	
	dfs(1);
	long long ans=0;
	for(int i=2;i<=n;++i){
		int part1=subtree_sum[i];
		int part2=subtree_sum[1]-part1;
		ans=max(ans,(part1*1LL*part2));
	}
	cout<<ans;
}
