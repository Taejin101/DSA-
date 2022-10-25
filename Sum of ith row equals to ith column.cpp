#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int n,m;
	cin>>n>>m;
	int arr[n+1][m+1];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
		{
			cin>>arr[i][j];
		}
	}
	
	int minimum=min(n,m);
	int flag=1;
	for(int i=1;i<=minimum;++i)					// O(N^2)
	{
		int sum1=0;
		int sum2=0;
		int j=1;
		while(j<=n&&j<=m)
		{
			sum1+=arr[i][j];
			sum2+=arr[j][i];
			++j;
		}
		while(j<=n)
		{
			sum2+=arr[j][i];
			++j;
		}
		while(j<=m)
		{
			sum1+=arr[i][j];
			++j;
		}
		if(sum1!=sum2)
		{
			flag=0;
			break;
		}
	 } 
	 if(flag)
	 {
	 	cout<<"1";
	 }
	 else
	 {
	 	cout<<"0";
	 }
	
}

