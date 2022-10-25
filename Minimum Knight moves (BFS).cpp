// https://www.spoj.com/problems/NAKANJ/
// Minimum Knight moves

#include <bits/stdc++.h>
using namespace std;

int level[8][8];
int vis[8][8];
const int INF=1e9+10;

vector<pair<int,int>> movements={
	{2,-1},{2,1},
	{-2,-1},{-2,1},
	{1,2},{-1,2},
	{1,-2},{-1,-2}
};

int getX(string s){
	return (s[0]-'a');
}

int getY(string s){
	return (s[1]-'1');
}

void reset(){
	for(int i=0;i<8;++i){
		for(int j=0;j<8;++j){
			level[i][j]=INF;
			vis[i][j]=0;
		}
	}
}

bool isValid(int i,int j){
	return (i>=0&&j>=0&&i<8&&j<8);
}

int bfs(string src, string des){
	int srcX=getX(src);
	int srcY=getY(src);
	int desX=getX(des);
	int desY=getY(des);
	
	queue <pair<int,int>> q;
	q.push({srcX,srcY});
	vis[srcX][srcY]=1;
	level[srcX][srcY]=0;
	
	while(!q.empty()){
		pair<int,int> pr=q.front();
		int x=pr.first,y=pr.second;
		q.pop();
		
		for(auto movement:movements){
			int newX=movement.first+x,newY=movement.second+y;
			if(!isValid(newX,newY)) continue;
			if(!vis[newX][newY]){
				q.push({newX,newY});
				vis[newX][newY]=1;
				level[newX][newY]=level[x][y]+1;
			}
		}
		
		if(level[desX][desY]!=INF)
			break;
	}
	
	return level[desX][desY];
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		reset();
		string src,des;
		cin>>src>>des;
		cout<<bfs(src,des)<<endl;
	}
}


