#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        
        for(int i=0;i<numRows;++i){
            vector<int> temp(i+1);
            temp[0]=temp[i]=1;
            for(int j=1;j<i;++j){
                temp[j]=triangle[i-1][j]+triangle[i-1][j-1];
            }
            triangle.push_back(temp);
        }
        return triangle;
    }
};

int main(){
	Solution s;
	vector<vector<int>> v=s.generate(10);
	
	for(auto vect:v){
		for(auto val:vect){
			cout<<val<<" ";
		}
		cout<<endl;
	}
}
