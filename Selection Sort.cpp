#include <iostream>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	
	for(int i=0;i<n;++i)							// Selection sort
	{
		int minindex=i;
		for(int j=i+1;j<n;++j)						// Searching for minimum index
		{
			if(a[j]<a[minindex])
			{
				minindex=j;
			}
		}
		if(minindex!=i)								// if minindex is another than i than swap with current i
		{
			swap(a[i],a[minindex]);
		}
	}
	
	for(int i=0;i<n;++i)							// displaying the array after sorting
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}

// Time complexity - O[n^2]
