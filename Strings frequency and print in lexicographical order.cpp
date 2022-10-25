// Given strings count the frequency of strings and print them in a lexographical order

#include <iostream>
#include <map>
using namespace std;

void print(map <string,int> &m)
{
	cout<<"Size of map : "<<m.size()<<endl;
	for(auto &it:m)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}

int main(void)
{
	int n;
	cin>>n;
	
	map <string,int> m;
	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		
		//m[s]=m[s]+1;
		m[s]++;
	}
	
	print(m);
}
