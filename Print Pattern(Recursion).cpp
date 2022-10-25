/*
1 2 3 4 5 
1 2 3 4 
1 2 3 
1 2 
1
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 0;

void print_pattern(int n){
    if(n == 1){
        cout << 1 << "\n";
        return;
    }
    for(int i = 1; i <= n; ++i){
        cout << i << " ";
    }    
    cout << "\n";
    print_pattern(n - 1);
    
    for(int i = 1; i <= n; ++i){
        cout << i << " ";
    }   
    cout << "\n";
}

int main()
{
    print_pattern(5);
}