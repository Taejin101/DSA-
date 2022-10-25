// Queue in STL

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	queue <string> q;
	
	q.push("abc");
	q.push("cde");
	q.push("efg");
	q.push("ghi");
	q.push("ijk");
	
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	return 0;
}
