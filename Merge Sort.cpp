// Merge Sort

#include <iostream>
using namespace std;

const int N=1e5+10;
int a[N];

void merge(int l,int r,int mid)					// Merges two sorted arrays 
{
	int size1=mid-l+1;
	int size2=r-mid;
	int L[size1+1];
	int R[size2+1];
	
	for(int i=0;i<size1;++i)
	{
		L[i]=a[l+i];
	}
	
	for(int i=0;i<size2;++i)
	{
		R[i]=a[mid+1+i];
	}
	
	L[size1]=R[size2]=INT_MAX;
	
	int l_i=0;
	int r_i=0;
	for(int i=l;i<=r;++i)
	{
		if(L[l_i]<=R[r_i])
		{
			a[i]=L[l_i];
			l_i++;
		}
		else
		{
			a[i]=R[r_i];
			r_i++;
		}
	}
}

void mergeSort(int l,int r)						// breaks the array until it is sorted
{
	if(l>=r)
		return;
	int mid=(l+r)/2;
	mergeSort(l,mid);
	mergeSort(mid+1,r);
	merge(l,r,mid);
}

int main(void)
{
	int n;
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
	}
	
	mergeSort(0,n-1);
	
	for(int i=0;i<n;++i)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
