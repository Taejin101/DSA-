//https://www.codechef.com/problems/REVERSE
// BFS to find shortest path for 0 and 1 wt edges

#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
const int INF=1e9+7;

vector<pair<int,int>> g[N];
vector<int> lev(N,INF);
int n,m;

int bfs(){
	deque<int>q;
	q.push_back(1);
	lev[1]=0;
	
	while(!q.empty()){
		int curr_v=q.front();
		q.pop_front();
		
		for(auto child:g[curr_v]){
			int child_v=child.first;
			int child_wt=child.second;
			if(lev[curr_v]+child_wt<lev[child_v]){
				lev[child_v]=lev[curr_v]+child_wt;
				if(child_wt==0)
					q.push_front(child_v);
				else
					q.push_back(child_v);
			}
		}
	}
	
	return (lev[n]==INF?-1:lev[n]);
}

int main(){
	cin>>n>>m;
	
	for(int i=0;i<m;++i){
		int v1,v2;
		cin>>v1>>v2;
		
		if(v1==v2) continue;
		g[v1].push_back({v2,0});
		g[v2].push_back({v1,1});
	}
	
	cout<<bfs();
}
