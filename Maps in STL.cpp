#include <iostream>
#include <map>
using namespace std;

void print(map <int,string> &m)
{
	cout<<"Size of map is "<<m.size()<<endl;
	
	for(auto &it:m)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}

int main(void)
{
	map <int,string> m;
	
	m[2]="abc";					// log(n) time complexity for inserting
	m[5]="cde";
	m[3]="a";
	m[5]="oab";					// existing value of 5 gets replaced 
	
//	m[2];						// log(n) time and 2 is inserted in map with second value as 0

	auto it=m.find(3);			// returns an iterator if found else returns m.end()
	
	if(it!=m.end())
		m.erase(it);			// can take two types of arguments either an iterator or a key value
		
	m.clear();					// clears the complete map
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
