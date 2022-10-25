// Sort function in STL

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
//	int n;
//	cin>>n;
//	
//	vector <int> arr(n);
//	for(int i=0;i<n;++i)
//	{
//		cin>>arr[i];
//	}
//	
//	// O(n) algorithm in STL
//	
//	int min=*min_element(arr.begin(),arr.end()); 			// it returns position of the min element
//	cout<<"Min_element : "<<min<<endl;
//	int max=*max_element(arr.begin(),arr.end());			// it returns position of the max element
//	cout<<"Max_element : "<<max<<endl;
//	int sum=accumulate(arr.begin(),arr.end(),0);			// it returns the sum from begin to end takes three arguments starting, ending+1 and initial sum
//	cout<<"Sum is : "<<sum<<endl;
//	int ct=count(arr.begin(),arr.end(),2);					// returns count of given number
//	cout<<"Count is : "<<ct<<endl;
//	auto it=find(arr.begin(),arr.end(),5); 					// returns iterator of element if found else returns v.end() iterator
//	if(it!=arr.end())
//	{
//		cout<<(*it)<<endl;
//	}
//	else
//	{
//		cout<<"Element not found"<<endl;
//	}
//	
//	reverse(arr.begin(),arr.end());							// reverses the array from v.begin() to v.end()
//	for(auto value:arr)
//	{
//		cout<<value<<" ";
//	}
//	cout<<endl;
//	
//	string s="Ishan";
//	reverse(s.begin(),s.end());
//	cout<<s<<endl;

//  FOR ARRAYS
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;++i)
	{
		cin>>arr[i];
	}
	
	int min=*min_element(arr,arr+n); 			// it returns position of the min element
	cout<<"Min_element : "<<min<<endl;
	int max=*max_element(arr,arr+n);			// it returns position of the max element
	cout<<"Max_element : "<<max<<endl;
	int sum=accumulate(arr,arr+n,0);			// it returns the sum from begin to end takes three arguments starting, ending+1 and initial sum
	cout<<"Sum is : "<<sum<<endl;
	int ct=count(arr,arr+n,2);					// returns count of given number
	cout<<"Count is : "<<ct<<endl;
	auto it=find(arr,arr+n,5); 					// returns iterator of element if found else returns v.end() iterator
	if(it!=arr+n)
	{
		cout<<(*it)<<endl;
	}
	else
	{
		cout<<"Element not found"<<endl;
	}
	
	reverse(arr,arr+n);							// reverses the array from v.begin() to v.end()
	for(auto value:arr)
	{
		cout<<value<<" ";
	}
	cout<<endl;
	
	string s="Ishan";
	reverse(s.begin(),s.end());
	cout<<s<<endl;
}
