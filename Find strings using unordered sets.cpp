#include <iostream>
#include <unordered_set>
using namespace std;

int main(void)
{
	int n;
	cin>>n;
	unordered_set <string> s;
	for(int i=0;i<n;++i)
	{
		string str;
		cin>>str;
		
		s.insert(str);
	}
	
	int q;
	cin>>q;
	
	while(q--)
	{
		string str;
		cin>>str;
		auto it=s.find(str);
		if(it!=s.end())
		{
			cout<<"Yes\n";
		}
		else
		{
			cout<<"No\n";
		}
	}
}

