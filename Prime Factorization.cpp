// Prime factors

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	cin>>n;
	
	vector<int> prime_factors;
	for(i=2;i*i<=n;++i){
		while(n%i==0){
			prime_factors.push_back(i);
			n/=i;
		}
	}
	// O(sqrt(N))
	if(n>1){
		prime_factors.push_back(n);
	}
	
	for(auto primes:prime_factors){
		cout<<primes<<" ";
	}
}
