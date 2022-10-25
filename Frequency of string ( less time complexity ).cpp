// print frequency of strings given improved time complexity

#include <iostream>
#include <unordered_map>
using namespace std;


int main(void)
{
	int n;
	cin>>n;
	
	unordered_map <string,int> m;
	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		//m[s]=m[s]+1;
		m[s]++;
	}
	
	int q;
	cin>>q;
	
	while(q--)
	{
		string s;
		cin>>s;
		cout<<m[s]<<endl;
	}
}
