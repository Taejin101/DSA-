// Longest Subarray with sum equal to k

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;++i){
		cin>>array[i];
	}
	int k;
	cin>>k;
	int sum=0,mxLength=0;
	unordered_map <int,int> m;
	for(int i=0;i<n;++i){
		sum+=array[i];
		if(sum==k)
			mxLength=i+1;
		if(m.find(sum)==m.end())
			m[sum]=i;
		if(m.find(sum-k)!=m.end()){
			if(mxLength<(i-m[sum-k]))
				mxLength=i-m[sum-k];
		}
	}
	cout<<mxLength<<endl;
}
