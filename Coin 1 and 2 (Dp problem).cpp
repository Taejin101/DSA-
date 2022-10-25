// https://leetcode.com/problems/coin-change-2/submissions/
// coin 1 and 2 dynamic programming

#include <bits/stdc++.h>
using namespace std;

int dp[310][5010];

int fun1(int ind,int amount,vector<int>& coins){
	if(amount==0) return 1;
	if(ind<0) return 0;
	if(dp[ind][amount]!=-1) return dp[ind][amount];
	
	int ways=0;
	for(int coin_amount=0;coin_amount<=amount;coin_amount+=coins[ind]){
		ways+=fun1(ind-1,amount-coin_amount,coins);
	}
	
	return dp[ind][amount]=ways;
}

int change(int amount, vector<int>& coins) {
    memset(dp,-1,sizeof(dp));
	int ans=fun1(coins.size()-1,amount,coins);
	return ans;    
}

int main(){
	vector<int> coins={10};
	cout<<change(10,coins);
}
