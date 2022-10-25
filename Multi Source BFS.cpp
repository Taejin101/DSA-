// Multi Source Bfs

#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int INF=1e9+10;
int n,m;
int val[N][N];
int lev[N][N];
int vis[N][N];

vector<pair<int,int>> movements={
	{1,0},{-1,0},{0,1},{0,-1},
	{-1,-1},{1,1},{1,-1},{-1,1}
};

bool isValid(int i,int j){
	return i>=0&&j>=0&&i<n&&j<m;
}

void reset(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			vis[i][j]=0;
			lev[i][j]=INF;
		}
	}
}

int bfs(){
	int mx=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			mx=max(mx,val[i][j]);
		}
	}
	
	queue<pair<int,int>> q;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(val[i][j]==mx){
				q.push({i,j});
				vis[i][j]=1;
				lev[i][j]=0;
			}
		}
	}
	
	int mx_level=0;
	while(!q.empty()){
		auto pr=q.front();
		q.pop();
		int v_x=pr.first;
		int v_y=pr.second;
		for(auto movement:movements){
			int child_x=v_x+movement.first;
			int child_y=v_y+movement.second;
			if(!isValid(child_x,child_y)) continue;
			if(vis[child_x][child_y]) continue;
			
			q.push({child_x,child_y});
			lev[child_x][child_y]=lev[v_x][v_y]+1;
			vis[child_x][child_y]=1;
			
			mx_level=max(mx_level,lev[child_x][child_y]);
		}
	}
	
	return mx_level;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		reset();
		cin>>n>>m;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>val[i][j];
			}
		}
		
		cout<<bfs()<<endl;
	}
}
