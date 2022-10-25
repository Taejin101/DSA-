// auto dynamically determines the data type of a variable
// range based loop for(auto value:container) can be used for any container and takes the copy of values one by one

#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector <int> v={1,2,3,4,5};
	
	for(auto &value:v)					// copy of v[i] is created in value which is time consuming therefore we use &value
	{
		cout<<value<<endl;
	}
}
