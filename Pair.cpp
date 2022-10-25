#include <iostream>
using namespace std;

int main(void)
{
	pair <int,int> p_array[3];
	/* p=make_pair(1,"abc");
	p={1,"abcd"};								// pairs can be initialized using this way also
	pair <int,string> &p1=p;					// using reference variable
	p1.first=3;
	cout<<p.first<<" "<<p.second<<endl;			// p.first = 3										*/
	
	for(int i=0;i<3;++i)
	{
		cin>>p_array[i].first>>p_array[i].second;
	}
	
	swap(p_array[0],p_array[2]);
	
	cout<<"After swap...\n";
	for(int i=0;i<3;++i)
	{
		cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
	}
	
	return 0;
}
