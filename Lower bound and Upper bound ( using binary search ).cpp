#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &v,int to_find)
{
	int lo=0;
	int hi=v.size()-1;
	
	while(hi-lo>1)
	{
		int mid=(hi+lo)/2;
		if(to_find>v[mid])
		{
			lo=mid+1;
		}
		else
		{
			hi=mid;
		}
	}
	
	if(v[lo]>=to_find)
	{
		return (lo);
	}
	else if(v[hi]>=to_find)
	{
		return (hi);
	}
	else
	{
		return (-1);
	}
}

int upper_bound(vector <int> &v,int to_find)
{
	int lo=0;
	int hi=v.size()-1;
	
	while(hi-lo>1)
	{
		int mid=(hi+lo)/2;
		if(to_find>=v[mid])
		{
			lo=mid+1;
		}
		else
		{
			hi=mid;
		}
	}
	
	if(v[lo]>to_find)
	{
		return (lo);
	}
	else if(v[hi]>to_find)
	{
		return (hi);
	}
	else
	{
		return (-1);
	}
}

int main(void)
{
    int n;
    cin>>n;
    
    vector <int> v(n);
    for(int i=0;i<n;++i)
    {
    	cin>>v[i];
	}
	
	sort(v.begin(),v.end());
	
	int to_find;
	cin>>to_find;
	
	int lb=lower_bound(v,to_find);
	int ub=upper_bound(v,to_find);
	cout<<"Lower bound is : "<<lb<<" "<<((lb!=-1)?v[lb]:-1)<<endl;
	cout<<"Upper bound is : "<<ub<<" "<<((ub!=-1)?v[ub]:-1)<<endl;
}
