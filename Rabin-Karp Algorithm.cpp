// Rabin - Karp Algorithm 

#include <bits/stdc++.h>
using namespace std;

const int m = 1e9 + 7;
const int N = 1e5 + 7;
int p = 31;
vector<long long> power(N, 1);

int main(){
    for(int i = 1; i < N; ++i){
        power[i] =( power[i - 1] * p ) % m;
    }
    string s = "Hie my name is Ishan Joshi. I am a good boy.";
    string p = "good";
    int S = s.size(), P = p.size();
    vector<long long> h(S+1, 0);
    for(int i = 0; i < S; ++i){
        h[i + 1] =( h[i] + (s[i] - 'a' + 1) * power[i] ) % m;
    }

    long long h_p = 0;
    for(int i = 0; i < P; ++i){
        h_p = (h_p + (p[i] - 'a' + 1) * power[i]) % m;
    }

    for(int i = 0; i + P - 1 < S; ++i){
        long long cur_h = (h[i + P] - h[i] + m) % m;
        if(cur_h == (h_p * power[i]) % m){
            cout<< "Found at index: "<<i<<endl;
        }
    }
}