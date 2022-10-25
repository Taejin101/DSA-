//Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.
/*	
5 3
1 2 100
2 5 100
3 4 100

After the first update the list is 100 100 0 0 0.
After the second update list is 100 200 100 100 100.
After the third update list is 100 200 200 200 100.

The maximum value is 200.

*/

#include <bits/stdc++.h>
using namespace std;

const int N=1e7+10;
long long int arr[N];

int main(void)
{
    int n,m;
    cin>>n>>m;
    
    while(m--)
    {
        int a,b;
        long long int k;
        cin>>a>>b>>k;
        arr[a]+=k;
        arr[b+1]-=k;
    }
    
    for(int i=1;i<=n;++i)
    {
        arr[i]+=arr[i-1];
    }
    
    long long int max=-1;
    for(int i=1;i<=n;++i)
    {
        if(max<arr[i])
            max=arr[i];
    }
    cout<<max<<endl;
}
