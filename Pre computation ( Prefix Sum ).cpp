#include<iostream>
using namespace std;

const int N=1e5+10;
int pf[N];
int a[N];

int main(void)									// 6 3 6 2 8 9 2
{
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pf[i]=pf[i-1]+a[i];
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		int l,r;
		cin>>l>>r;
		cout<<pf[r]-pf[l-1]<<endl;
	}
}
