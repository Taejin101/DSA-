// Sort function in STL

#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b)				// returns false if needs to be swap else true
{
	return (a>b);
}

int main(void)
{
	int n;
	cin>>n;
	
//	int arr[n];
	vector<int> v(n);
	for(int i=0;i<n;++i)
	{
		cin>>v[i];
	}
	
//	sort(v.begin(),v.end());					// takes the starting address and last+1 address to sort start to last elements
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n;++i)
	{
		cout<<v[i]<<" ";
	}
}
