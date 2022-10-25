// Inclusion Exclusion Principle
// The three musketeers hackerearth code monk series

#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch){
	return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}

vector<string> subset(string &s){
	vector<string> ans;
	int sz=1<<s.size();
	for(int masks=0;masks<sz;++masks){
		string str;
		for(int bit=0;bit<s.size();++bit){
			if(masks & (1<<bit))
				str.push_back(s[bit]);
		}
		if(str.size())ans.push_back(str);
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n;
		cin>>n;
		string s[n];
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		
		unordered_map<string,int> hsh;
		for(auto str:s){
			set<char> distinct_vwl;
			for(auto ch:str){
				if(isVowel(ch))
					distinct_vwl.insert(ch);
			}
			string vwl_string;
			for(auto ch:distinct_vwl){
				vwl_string.push_back(ch);
			}
			vector<string> all_subsets=subset(vwl_string);
			for(auto str:all_subsets){
				++hsh[str];
			}
		}
		long long ans=0;
		for(auto &pr:hsh){
			if(pr.second<3) continue;
			long long ct=pr.second;
			long long ways=ct*(ct-1)*(ct-2)/6;
			if(pr.first.size()&1) ans+=ways;
			else ans-=ways;
		}
		cout<<ans<<endl;
	}
}
