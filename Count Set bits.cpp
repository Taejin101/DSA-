// Count Set bits

#include <bits/stdc++.h>
using namespace std;

int CountSetBit(int num)
{
	int ct=0;
	for(int i=10;i>=0;i--)
	{
		if(1&num>>i){
			ct++;
		}
	}
	return ct;
}

void printBinary(int num)
{
	for(int i=10;i>=0;i--)
	{
		cout<< (num>>i&1);
	}
	cout<<"\n";
}

int main(void)
{
	int x=7;
	
	printBinary(x);
	cout<<CountSetBit(x);
	cout<<endl;
	
	// inbuilt function to count set bits
	cout<<__builtin_popcount(x)<<endl;					// for integers
	cout<<__builtin_popcountll((1LL<<35)-1)<<endl;		// for long long
	
}
