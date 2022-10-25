#include <iostream>
#include <unordered_set>
using namespace std;

void print(unordered_set <string> &s)
{
	unordered_set<string>::iterator it;
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
	unordered_set <string> s;
	s.insert("abc");						// O(1) time complexity
	s.insert("zebra");
	s.insert("ishan");
	
//	auto it=s.find("abcd");					// O(1)
//	if(it!=s.end())
//	{
//		cout<<*it<<endl;
//	}

	print(s);
}

