#include <bits/stdc++.h>
using namespace std;

int isOdd(int n){
	// checks whether given number is odd or not
	return (n&1);			
}

int multiplyBy2(int n){
	return (n<<1);
}

int divideBy2(int n){
	return (n>>1);
}

void printBinary(int n){
	for(int i=10;i>=0;i--){
		cout<< ((n>>i)&1);
	}
	cout<<"\n";
}

int main(void){
	
//	for(int i=2;i<4;++i){
//		cout<<i<<endl;
//	    if(isOdd(i)){
//	    	cout<<"Odd no\n";
//		}else{
//			cout<<"Even no\n";
//		}
//	}
//	
//	cout<<multiplyBy2(5)<<endl;
//	cout<<divideBy2(5)<<endl;

//	In binary of upper case characters 5th bit is unset whereas in binary of lower case character 5th bit is set

//	char A='A';
//	cout<< char(A|(1<<5));
//  0100000 is binary of 32 and it is ' ' space
//	cout<< char(A|' ');
//	
//	cout<<"\n";
//	
//	char a='a';
//	1011111 is binary of '_' underscore
//	cout<< char(a&~(1<<5));
//	cout<< char(a&'_');

//  clear LSB
//	int a=65;
//	printBinary(a);
//	int n=4;
//	printBinary(a&~((1<<n+1)-1)) ;
	
//	clear MSB
//	int a=59;
//	printBinary(a);
//	int n=3;
//	printBinary(a&((1<<n+1)-1)) ;

//	check power of 2
int n=8;
	if((n&n-1)==0){
		cout<<"yes power of 2";
	}else{
		cout<<"no not power of 2";
	}
	
}
