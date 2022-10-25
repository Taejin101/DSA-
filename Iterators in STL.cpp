#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	/*
	vector <int> v={1,2,3,4,5};
	
	vector <int>::iterator it=v.begin();
	
	// cout<<*(it+1)<<endl;
	
	for(;it!=v.end();++it)								// iterating all values using iterator
	{													// it++ -> moves iterator to the next iterator
		cout<<*(it)<<endl;								// it+1 -> moves iterator to the next location
	}
	*/
	
	vector <pair<int,int>> v={{1,2},{3,4},{5,6}};
	vector <pair<int,int>> :: iterator it;
	
	for(it=v.begin();it!=v.end();++it)
	{
		cout<<it->first<<" "<<it->second<<endl;			// accessing pairs using iterators
	}													
	
}
