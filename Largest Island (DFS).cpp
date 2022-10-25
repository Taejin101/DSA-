//https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?page=1&status[]=unsolved&company[]=Amazon&category[]=Graph&sortBy=submissions#
// largest island 8 sides
#include <bits/stdc++.h>
using namespace std;

void dfs(int i,int j, vector<vector<int>> &grid){
	int row=grid.size();
	int col=grid[0].size();
	if(i<0||j<0||i>=row||j>=col||grid[i][j]==0) return;
	
	grid[i][j]=0;
	
	dfs(i+1,j,grid);
	dfs(i-1,j,grid);
	dfs(i,j+1,grid);
	dfs(i,j-1,grid);
	dfs(i+1,j+1,grid);
	dfs(i+1,j-1,grid);
	dfs(i-1,j+1,grid);
	dfs(i-1,j-1,grid);
}

int findMaxArea(vector<vector<int>>& grid) {
	int row=grid.size();
	int col=grid[0].size();
	int ct=0;
  	for(int i=0;i<row;++i){
  		for(int j=0;j<col;++j){
  			if(grid[i][j]==0) continue;
  			ct++;
  			dfs(i,j,grid);
		}
	}
	return ct;
}

int main(){
	vector<vector<int>> grid = {{0,1}};
	cout<<findMaxArea(grid);
}
