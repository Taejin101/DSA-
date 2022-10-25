// Rod Cutting problem
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1#

#include <bits/stdc++.h>
using namespace std;

int dp[1005];
int N;

int fun(int price[],int n){
	if(n==0) return 0;
	if(dp[n]!=-1) return dp[n];
	int mx=0;
	for(int i=0;i<N;++i){
		if(n-i-1>=0)
			mx=max(mx,fun(price,n-i-1)+price[i]);
	}
	return dp[n]=mx;
}

int cutRod(int price[], int n) {
	memset(dp,-1,sizeof(dp));
	N=n;
    int ans=fun(price,n);
	return ans;    
}

int main(){
	int price[]={1, 5, 8, 9, 10, 17, 17, 20};
	cout<<cutRod(price,8);
}
