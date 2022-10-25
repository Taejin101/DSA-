// Square root of a number using binary search

#include <bits/stdc++.h>
using namespace std;

double eps=1e-6;
int main(void)
{
	double x;
	cin>>x;
	
	double hi=x;
	double lo=1;
	
	while(hi-lo>eps)
	{
		double mid=(hi+lo)/2;
		if(mid*mid>x)
		{
			hi=mid-1;
		}
		else
		{
			lo=mid;
		}
	}
	
	cout<<lo<<" "<<hi<<endl;
	cout<<"Using pow function : "<<pow(x,1.0/2)<<endl;
}
