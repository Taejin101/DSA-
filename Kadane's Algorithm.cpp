#include <bits/stdc++.h>
using namespace std;

int kadane_algorithm(vector<int> &nums){
    int mx_sum=nums[0];
    int mx_sum_till_now=nums[0];
    if(mx_sum_till_now<0)   mx_sum_till_now=0;
    for(int i=1;i<nums.size();++i){
        mx_sum=max(mx_sum, mx_sum_till_now+nums[i]);
        mx_sum_till_now+=nums[i];
        if(mx_sum_till_now<0)   mx_sum_till_now=0;
    }
    return mx_sum;
}

int main(){
    vector<int> nums={-5,-2,-3,-4};
    int mx_sum=kadane_algorithm(nums);
    cout<<mx_sum<<endl;
}