#include <iostream>
#include <set>
using namespace std;

void print(set <string> &s)
{
	set<string>::iterator it;
	for(it=s.begin();it!=s.end();it++)
	{
		cout<<*it<<endl;
	}
	
	for(auto value:s)
	{
		cout<<value<<endl;
	}
}

//set.isEmpty()	checks whether set is empty or not		

int main(void)
{
	set <string> s;
	s.insert("abc");						// log(n) time complexity
	s.insert("zebra");
	s.insert("ishan");
	
	auto it=s.find("abcd");					// log(n)
	if(it!=s.end())
	{
		cout<<*it<<endl;
	}
	//print(s);
}

