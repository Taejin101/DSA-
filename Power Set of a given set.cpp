// Power Set

#include <bits/stdc++.h>
using namespace std;

vector <vector<int>> v;

void generate(vector <int> &set,int i,vector <int> nums)
{	
	if(i==nums.size())
	{
		v.push_back(set);
		return;
	}
	// ith integer not included
	generate(set,i+1,nums);
	
	// (i)th integer included
	
	set.push_back(nums[i]);
	generate(set,i+1,nums);
	set.pop_back();
}

int main(void)
{
	int n;
	cin>>n;
	
	vector <int> num(n);
	for(int i=0;i<n;++i)
	{
		cin>>num[i];
	}
	
	vector<int> set;
	generate(set,0,num);
	
	for(auto &value:v)
	{
		for(auto ele:value)
		{
			cout<<ele<<" ";
		}
		cout<<endl;
	}
}
