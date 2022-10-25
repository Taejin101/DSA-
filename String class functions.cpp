// string functions

#include <bits/stdc++.h>
using namespace std;

vector<string> m_strings;
int main(){
	int q;
	cin>>q; 
	
	string str="";
	
	while(q--){			// 8
		int t;
		cin>>t;
		
		if(t==1){
			m_strings.push_back(str);
			string add;
			cin>>add;
			
			str.append(add);
		}else if(t==2){
			m_strings.push_back(str);
			int k;
			cin>>k;
			
			int pos=str.size()-k;
			str.erase(pos,str.size());
		}else if(t==3){
			int k;
			cin>>k;
			cout<<str[k-1]<<'\n';
		}else if(t==4){
			if(!m_strings.empty()){
				auto it= --m_strings.end();
				str=*it;
				m_strings.erase(it);
			}
		}
	}	
}
