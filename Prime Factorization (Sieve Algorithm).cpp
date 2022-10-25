// Sieve Algorithm Lowest and Highest primes
// Finding prime factorization using sieve algorithm

#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool> is_Prime(N, 1);
vector<int> lp(N,0);
vector<int> hp(N);

int main(){
	is_Prime[0]=is_Prime[1]=false;
	for(int i=2;i<=N;++i){
		if(is_Prime[i]==true){
			lp[i]=hp[i]=i;
			for(int j=2*i;j<=N;j+=i){
				is_Prime[j]=false;
				hp[j]=i;
				if(lp[j]==0)
					lp[j]=i;
			}
		}
	}
	
	// prime factorization
	vector<int> prime_factors;
	map<int,int> factors;
	int num;
	cin>>num;
	
	while(num>1){
		int primes=hp[num];
		while(num%primes==0){
			num/=primes;
			prime_factors.push_back(primes);
			factors[primes]++;
		}
	}
	
	for(auto it: factors){
		cout<<it.first<<" "<<it.second<<endl;;
	}
}
