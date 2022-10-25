// KMP Algorithm of pattern search

#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_func(string s){
    int n=s.size();
    vector<int> prefix(n,0);
    prefix[0]=0;
    for(int i=1;i<n;++i){
        int j=prefix[i-1];
        while(j>0 && s[i]!=s[j])
             j=prefix[j-1];
        if(s[i]==s[j]) j++;
        prefix[i]=j;
    }
    return prefix;
}

int main(){
    string s1="apnacollege";
    string s2="na";
    vector<int> prefix=prefix_func(s2);
    int i(0),j(0);
    int cnt(0);
    while(i<(s1.size())){
        if(s1[i]==s2[j]){
            i++;
            j++;
        }else{
            if(j!=0)
                j=prefix[j-1];
            else
                i++;
        }
        if(j==s2.size()){
            cnt++;
            j=prefix[j-1];
        }
    }
    cout<<"Matching string found  "<<cnt<<endl;
}
