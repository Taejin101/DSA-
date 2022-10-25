// Nesting

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	map <pair<string,string>,vector <int>> m;
	int n;
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		string fn,ln;
		int k;
		cin>>fn>>ln>>k;
		for(int j=0;j<k;++j)
		{
			int x;
			cin>>x;
			m[{fn,ln}].push_back(x);
		}
	}
	
	for(auto &it:m)
	{
		auto &full_name=it.first;
		auto &list=it.second;
		cout<<full_name.first<<" "<<full_name.second<<endl;
		cout<<list.size()<<endl;
		for(auto &value:list)
		{
			cout<<value<<" ";
		}
		cout<<endl;
	}
}
