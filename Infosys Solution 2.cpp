// Your birthday is coming soon and one of your friends, Alex, is thinking about a gift for you. 
// He knows that you really like integer arrays with interesting properties.
// He selected two numbers, N and K and decided to write down on paper all integer arrays of 
// length K (in form a[1], a[2], …, a[K]), where every number a[i] is in range from 1 to N, and, 
// moreover, a[i+1] is divisible by a[i] (where 1 < i <= K), and give you this paper as a 
// birthday present.
// Alex is very patient, so he managed to do this. Now you’re wondering, how many different 
// arrays are written down on this paper?
// Since the answer can be really large, print it modulo 10000.
// Input:
// • The first line contains an integer, n, denoting the maximum possible value in the 
// arrays.
// • The next line contains an integer, k, denoting the length of the arrays.
// Sample Input:
// 2
// 1
// Sample Output:
// 2
// Explanation: 
// The required length is 1, so there are only two possible arrays: [1] and [2]




#include <bits/stdc++.h>
using namespace std;

int bin_exp(int a, int b, int mod){
    int ans = 1;
    while(b > 0){
        if(b & 1){
            ans = (ans * 1LL * a) % mod;
        }
        a = (a * 1LL * a) % mod;
        b >>= 1;
    }
    return ans;
}

int no_of_arrays(int n, int k){
    int array_count = 0;
    int mod = 1e4;
    for(int i = 1; i <= n; ++i){
        array_count += bin_exp(n / i, k - 1, mod);
    }
    return array_count;
}

int main(){
    int n, k;
    cin >> n >> k;

    cout << no_of_arrays(n, k);
}