// Sieve Algorithm Prime check

#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
vector<bool> is_Prime(N, 1);

int main(){
	is_Prime[0]=is_Prime[1]=false;
	for(int i=2;i<=N;++i){
		if(is_Prime[i]==true){
			for(int j=2*i;j<=N;j+=i){
				is_Prime[j]=false;
			}
		}
	}
	
	for(int i=1;i<=100000;i++){
		if(is_Prime[i]==true){
			cout<<i<<endl;
		}
	}
	
//	int q;
//	cin>>q;
//	
//	while(q--){
//		int x;
//		cin>>x;
//		
//		if(is_Prime[x]==true){
//			cout<<"Yes, it is prime\n";
//		}else{
//			cout<<"No, not prime\n";
//		}
//	}
}
