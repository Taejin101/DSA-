// Set bit or not

#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int x=9;					// 1001
	int a=1;
	
	if((x&1<<a)!=0)
	{
		cout<<"Set bit";
	}
	else
	{
		cout<<"Not Set bit";
	}
}
