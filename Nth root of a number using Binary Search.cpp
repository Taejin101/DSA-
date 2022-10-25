// nth root of a number using binary search

#include <bits/stdc++.h>
using namespace std;

double eps=1e-6;

double multiply(double mid,int n)
{
	double ans=1;
	for(int i=1;i<=ans;++i)
	{
		ans*=mid;
	}
	
	return (ans);
}
int main(void)
{
	double x;
	cin>>x;
	
	int n;
	cin>>n;
	
	double hi=x;
	double lo=1;
	
	while(hi-lo>eps)
	{
		double mid=(hi+lo)/2;
		if(multiply(mid,n)>x)
		{
			hi=mid;
		}
		else
		{
			lo=mid;
		}
	}
	
	// Time complexity : p*log(N*10^d)
	
	cout<<lo<<" "<<hi<<endl;
	cout<<"Using pow function : "<<pow(x,1.0/n)<<endl;
}
