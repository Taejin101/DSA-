#include <bits/stdc++.h>
using namespace std;

int sum(int i,int a[])
{
	if(i<0)
	{
		return 0;
	}
	return (a[i]+sum(i-1,a));
}

int main(void)
{
	int n;
	cin>>n;
	
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	cout<<sum(n-1,a);
}
