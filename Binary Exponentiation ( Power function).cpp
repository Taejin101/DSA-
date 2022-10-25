// Binary Exponentiation 
// Power function

#include <bits/stdc++.h>
using namespace std;

const int M=1e9+7;

int binExpRecur(int a, int b){
	if(b==0)	return 1;
	
	int res=binExpRecur(a,b/2);
	if(b&1){
		return (a * 1LL *((res * 1LL * res)%M)%M);
	}else{
		return ((res * 1LL * res)%M);
	}
}

int binExpIter(int a, int b){
	int ans=1;
	while(b>0){
		if(b&1){
			ans=(ans*1LL*a)%M;
		}
		a=(a*1LL*a)%M;
		b>>=1;
	}
	return ans;
}

int main(){
	int a=2,b=1e5;
	cout<< binExpRecur(a,b)<<endl;
	cout<< binExpIter(a,b)<<endl;
	cout<< pow(a,b)<<endl;
}
