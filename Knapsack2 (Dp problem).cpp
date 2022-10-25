// https://atcoder.jp/contests/dp/tasks/dp_e
// Knapsack 2 problem

#include <bits/stdc++.h>
using namespace std;

int wt[105],val[105];
long long dp[105][100005];

long long fun1(int v,int ind){
	if(v==0) return 0;
	if(ind<0) return 1e15;
	if(dp[ind][v]!=-1) return dp[ind][v];
	
	long long mn=fun1(v,ind-1);
	if(v-val[ind]>=0)
		mn=min(mn,fun1(v-val[ind],ind-1)+wt[ind]);
		
	return dp[ind][v]=mn;
}

int main(){
	memset(dp,-1,sizeof(dp));
	int n,w;
	cin>>n>>w;
	
	for(int i=0;i<n;++i){
		cin>>wt[i]>>val[i];
	}
	
	for(int i=1e5;i>=0;--i){
		if(fun1(i,n-1)<=w){
			cout<<i<<endl;
			break;
		}
	}
}
