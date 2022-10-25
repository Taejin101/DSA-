#include <iostream>
#define MAX 25
using namespace std;

int main(void)
{
	int a[MAX];
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	
	int temp=a[n-1];
	
	for(int i=0;i<n;++i)
	{
		temp=temp^a[i];
		a[i]=temp^a[i];
		temp=temp^a[i];
	}
	
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	
}
