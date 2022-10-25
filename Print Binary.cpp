// print binary upto 10 bits

#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
	for(int i=10;i>=0;i--)
	{
		cout<<((num>>i)&1);
	}

}
int main(void)
{
	printBinary(9);
}
