// all_of, any_of and none_of

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	vector <int> v={-1,3,5};
	
	cout<<all_of(v.begin(),v.end(),[](int x){return (x>0);});			// 0
	
	cout<<any_of(v.begin(),v.end(),[](int x){return (x>0);});			// 1
	
	cout<<none_of(v.begin(),v.end(),[](int x){return (x>0);});			// 0
	
}
