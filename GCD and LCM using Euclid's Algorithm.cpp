#include <bits/stdc++.h>
using namespace std;

int GCD(int a, int b){
	if(b==0) 
		return a;
	return GCD(b,a%b);
}

int main(){
	cout<< GCD(12,4)<<endl;
	cout<< GCD(18,12)<<endl;
	cout<< GCD(12,18)<<endl;
	cout<< 12*18/GCD(12,18)<<endl;		// LCM
	
	cout<< __gcd(12,18)<<endl;			// inbuilt function
}
