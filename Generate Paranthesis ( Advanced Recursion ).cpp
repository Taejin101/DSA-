// Generate Paranthesis

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int cnt = 0;

int max_xor(vector<int> &arr, int n)
{
    int maxx = 0, mask = 0;
 
    set<int> se;
 
    for (int i = 30; i >= 0; i--) {
        mask |= (1 << i);
 
        for (int i = 0; i < n; ++i) {
 
            // Just keep the prefix till
            // i'th bit neglecting all
            // the bit's after i'th bit
            se.insert(arr[i] & mask);
        }
 
        int newMaxx = maxx | (1 << i);
 
        for (int prefix : se) {
            if (se.count(newMaxx ^ prefix)) {
                maxx = newMaxx;
                break;
            }
        }
        se.clear();
    }
 
    return maxx;
}

void generate(string &s,int open,int close)
{
	if(open==0&&close==0)
	{
		cnt++;
		return;
	}
	
	if(open>0)
	{
		s.push_back('(');
		generate(s,open-1,close);
		s.pop_back();
	}
	
	if(close>0)
	{
		if(open<close)
		{
			s.push_back(')');
			generate(s,open,close-1);
			s.pop_back();
		}
	}
}

int main(void)
{
	int n, k;
	cin>>n>>k;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	int x = max_xor(a, n);
	
	string s;
	generate(s,x,x);
	
	int ans = cnt * 1ll * k % M;
	
	cout << ans;
}
