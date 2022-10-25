#include <iostream>
#include <vector>

using namespace std;

void print_vector(vector <string> &v)			// here also entire vector is getting copied in O(N) time complexity to reduce this we can always use reference variable 
{
	cout<<"size: "<<v.size()<<endl;
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

int main(void)
{
	/* vector <int> v;
	// cout<<v.size();			size() function returns the size of vector in O(1)
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int x;
		cin>>x;
		v.push_back(x);			// this function pushes back the integer in O(1)
	}
	print_vector(v);	
	
	vector <int> v(10);
	v.push_back(7);				// pushes the element at the end of an vector in O(1)
	v.push_back(6);	
	
	vector <int> v2=v;			// copies the entire vector in O(N) time complexity
	v2.push_back(5);
	// v.pop_back();			// pops the last element of the vector in O(1)
	print_vector(v);
	print_vector(v2);			*/
	
	vector <string> v;			// vectors can also be of strings, containers and pairs also
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		string s;
		cin>>s;
		v.push_back(s);
	}
	
	print_vector(v);
	
	return 0;
}
