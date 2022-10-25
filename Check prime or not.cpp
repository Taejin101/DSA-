// Prime number check

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,i;
	cin>>n;
	
	for(i=2;i*i<=n;++i){
		if(n%i==0){
			break;
		}
	}
	
	if(i*i>=n){
		cout<<"Yes is prime\n";
	}else{
		cout<<"No is not prime\n";
	}
}
