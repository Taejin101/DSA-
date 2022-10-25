// Comparison in STL containers

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
//	pair <int,int> p1;
//	pair <int,int> p2;
//	p1={1,1};
//	p2={1,2};
//	
//	cout<<(p2==p1)<<endl;				// first, first elements gets compared,if found equal then only second elements get compared
	
	set <int> s1={1,2,3};
	set <int> s2={2,3};
	
	cout<<(s1<s2)<<endl;				// comparison happens same as above 
	return 0; 
}

// Every container which can be compared can be used as a key in map container
