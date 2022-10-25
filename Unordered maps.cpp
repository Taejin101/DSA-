#include <iostream>
#include <unordered_map>
using namespace std;

void print(unordered_map <int,string> &m)
{
	cout<<"Size of map is "<<m.size()<<endl;
	
	for(auto &it:m)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}

int main(void)
{
//	unordered_map <pair<int,int>,string> m; cannot have complex data type in unordered map since there is no hash function defined for it
	unordered_map <int,string> m;
	
//	Difference b/w map and unordered map 
//	1. Implementation (Map via trees and unordered map via hash table)
//	2. Time complexity (O(1))
//	3. 
	
	m[2]="abc";					// O(1) time complexity for inserting
	m[5]="cde";
	m[3]="a";
	m[5]="oab";					// existing value of 5 gets replaced 
	
//	m[2];						// o(1) time and 2 is inserted in map with second value as 0

	auto it=m.find(3);			// returns an iterator if found else returns m.end()
	
	if(it!=m.end())
		m.erase(it);			// can take two types of arguments either an iterator or a key value
		
//	m.clear();					// clears the complete map
	print(m);
	
//	if(it==m.end())
//	{
//		cout<<"Not found";
//	}
//	else
//	{
//		cout<<it->first<<" "<<it->second;
//	}
}
