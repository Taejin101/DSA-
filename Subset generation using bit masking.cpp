// Subset generation using bit masking

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{	
	int n=nums.size();
	
	vector <vector<int> > allSubsets;
	for(int masks=0;masks<(1<<n);++masks){
		vector <int> subset;
		for(int i=0;i<n;++i){
			if((masks&1<<i) != 0){
				subset.push_back(nums[i]);
			}
		}
		allSubsets.push_back(subset);
	}
	
	return (allSubsets);
}

int main(){
	int n;
	cin>>n;
	
	vector <int> nums(n);
	for(int i=0;i<n;++i){
		cin>>nums[i];
	}
	
	auto subset=subsets(nums);
	
	for(auto &v:subset){
		for(auto ele:v){
			cout<<ele<<" ";
		}
		cout<<"\n";
	}
}
