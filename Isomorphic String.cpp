#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s1,string s2){
    unordered_map <char,int> hsh;
    if(s1.size()!=s2.size())
        return false;

    for(int i=0;i<s1.size();i++){
        if(hsh.find(s1[i])==hsh.end()){
            hsh[s1[i]]=s1[i]-s2[i];
        }else{
            if(hsh[s1[i]]!=(s1[i]-s2[i]))
                return false;
        }
    }
    return true;
}

int main(){
    string s1="aab";
    string s2="xyz";

    bool ans= isIsomorphic(s1,s2);
    if(ans)
        cout<<"True";
    else
        cout<<"False";
    return 0;
}