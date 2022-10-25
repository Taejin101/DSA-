// Binary Search : It can be applied on any monotonic function ( which follows a particular order )
#include <bits/stdc++.h>
using namespace std;

void Binary_Search(vector <int> &v,int to_find)
{
	int lo=0;
	int hi=v.size()-1;
	
	while((hi-lo)>1)
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
	
	if(v[lo]==to_find)
	{
		cout<<lo<<endl;
	}
	else if(v[hi]==to_find)
	{
		cout<<hi<<endl;
	}
	else
	{
		cout<<"NOT FOUND"<<endl;
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
	
	int to_find;
	cin>>to_find;
	
	Binary_Search(v,to_find);	
}
