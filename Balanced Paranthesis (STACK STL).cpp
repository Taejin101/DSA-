// Balanced Paranthesis using Stack (STL)

#include <bits/stdc++.h>
using namespace std;

unordered_map <char,int> m={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};

string isBalanced(string s) {
	stack <char> st;
	for(auto ch:s)
	{
		if(m[ch]<0)
		{
			st.push(ch);
		}
		else
		{
			if(st.empty())
			{
				return ("No");
			}
			char top=st.top();
			st.pop();
			if(m[top]+m[ch]!=0)
			{
				return ("No");
			}
		}
	}
	if(st.empty())
		return ("Yes");
	return ("No");
}

int main(void)
{
	int n;
	cin>>n;
	
	while(n--)
	{
		string s;
		cin>>s;
		string result=isBalanced(s);
		if(result=="Yes"){
			cout<<"true\n";
		}else{
			cout<<"false\n";
		}
	}
	
}
