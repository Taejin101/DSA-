#include <iostream>
#include <vector>
using namespace std;

void print_vector(vector<int> &v)
{
	cout<<"Size of vector is : "<<v.size()<<endl;
	for(int i=0;i<v.size();++i)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

/*
int main(void)
{
	/*
	// vector<pair<int,int>> v={{1,2},{3,4},{5,6}};
	
	vector<pair<int,int>> v;
	
	int n;													// User input
	cin>>n;
	
	for(int i=0;i<n;++i)
	{
		int x,y;
		cin>>x>>y;
		v.push_back({x,y});
	}
	
	print_vector(v);
	
	int N;							// Array of vectors i.e it can be imagined as a 2D array having fixed rows but no fixed column
	cin>>N;
	
	vector <int> v[N];
	
	for(int i=0;i<N;++i)
	{
		int n;
		cin>>n;
		
		for(int j=0;j<n;++j)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}
	}
	
	for(int i=0;i<N;++i)
	{
		print_vector(v[i]);
	}
	
	
	return 0;
}*/

int main(void)
{
	vector <vector<int>> v;		// vectors of vector i.e it can be imagined as a 2D array having no fixed rows and column
	
	int N;
	cin>>N;
	
	for(int i=0;i<N;++i)
	{
		int n;
		cin>>n;
		
		/*
		v.push_back(vector <int> ());
		for(int j=0;j<n;++j)
		{
			int x;
			cin>>x;
			v[i].push_back(x);
		}*/
		
		vector <int> temp;
		for(int j=0;j<n;++j)
		{
			int x;
			cin>>x;
			temp.push_back(x);
		}
		v.push_back(temp);	
	} 
	
	for(int i=0;i<v.size();++i)
	{
		print_vector(v[i]);
	}
}


