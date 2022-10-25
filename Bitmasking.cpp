/*Consider this problem: There are N=5000 workers. 
Each worker is available during some days of this month (which has 30 days).
For each worker, you are given a set of numbers, each from interval [1,30], 
representing his/her availability. You need to assign an important project 
to two workers but they will be able to work on the project only when they 
are both available. Find two workers that are best for the job — maximize the 
number of days when both these workers are available.*/

// bitmasking
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector <int> masks(n,0);
	
	for(int i=0;i<n;++i){
		int days;
		cin>>days;
		for(int j=0;j<days;++j){
			int x;
			cin>>x;
			masks[i]=(masks[i]|(1<<x));
		}
	}
	
	int maxDays=-1;
	int person1=-1;
	int person2=-1;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			int intersection=masks[i]&masks[j];
			int commonDays=__builtin_popcount(intersection);
			if(commonDays>maxDays){
				maxDays=commonDays;
				person1=i;
				person2=j;
			}
		}
	}
	
	cout<<person1<<" "<<person2<<" "<<maxDays;
}
