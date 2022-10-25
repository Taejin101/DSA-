// Large exponentiation using binary multiply

#include <bits/stdc++.h>
using namespace std;

const int M=1e18+7;

long long binMultiply(long long a,long long b){
	long long ans=0;
	while(b>0){
		if(b&1){
			ans=(ans+a)%M;
		}
		a=(a+a)%M;
		b>>=1;
	}
	return ans;
}

int binExp(long long a, long long b){
	int ans=1;
	while(b>0){
		if(b&1){
			ans=binMultiply(ans,a)%M;
		}
		a=binMultiply(a,a)%M;
		b>>=1;
	}
	return ans;
}

int main(){
	int a=2,b=1e5;
	cout<< binExp(a,b)<<endl;
	cout<< binExp(a,b)<<endl;
	cout<< pow(a,b)<<endl;
}
