#include <iostream>
#include <set>
using namespace std;

void print(multiset <string> &s)
{
	multiset<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
	
	for(auto value:s)
	{
		cout<<value<<endl;
	}
}

int main(void)
{
	multiset <string> s;
	s.insert("abc");						// log(n) time complexity
	s.insert("zebra");
	s.insert("ishan");
	s.insert("abc");						// can insert multiple values 
	
//	auto it=s.find("abc");					// 1st abc's iterator will return 
//	if(it!=s.end())
//	{
//		s.erase(it);						// passing iterator in erase
//	}
	
	s.erase("abc");							// all abc get erased because it searches for abc until any iterator is not found

	print(s);
}

