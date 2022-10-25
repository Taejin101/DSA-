#include <bits/stdc++.h>
using namespace std;

int main(void){
//  swap two numbers
	int a=10,b=20;
	
//	a^a=0
//	a^0=a
	a=a^b;
	
	b=a^b;
//    b= (a^b)^b = a	
	
	a=a^b;
//	a=(a^b)^a = b
	
	cout<<a <<" " <<b;


	
	
}
