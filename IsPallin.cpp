// Given a string and queries for a given query tell whether the l to r 
// can be rearranged to form a pallindrome
// 2
// 5 5
// abcec
// 1 2
// 2 5
// 3 5
// 1 5
// 1 4
// 5 5
// aabbc
// 1 2
// 2 5
// 3 5
// 1 5
// 1 4


#include <bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int hsh[N][26];

int main()
{
    int t;
    cin>>t;
    while(t--){
        for(int i=0;i<N;++i){
            for(int j=0;j<26;++j){
                hsh[i][j]=0;
            }
        }
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        for(int i=0;s[i];++i){
            hsh[i+1][s[i]-'a']++;
        }
        for(int i=1;i<=n;++i){
            for(int j=0;j<26;++j){
                hsh[i][j]+=hsh[i-1][j];
            }
        }

        while(q--){
            int l,r;
            cin>>l>>r;

            int oddct=0;
            for(int i=0;i<26;++i){
                int charct=hsh[r][i]-hsh[l-1][i];
                if((charct&1)==1) oddct++;
            }

            if(oddct>1) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
    }
    return 0;
}