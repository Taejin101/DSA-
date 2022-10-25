// STACK in STL

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack <int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	
	while(!s1.empty())
	{
		cout<<s1.top()<<endl;
		s1.pop();
	}
	
	return 0;
}
