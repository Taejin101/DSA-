#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;
void solve();
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("error.txt", "w", stderr);
   freopen("output.txt", "w", stdout);
   #endif
   
   int t=1;
   /*is Single Test case?*/cin>>t;
   while(t--)
   {
      solve();
      cout<<"\n";
   }
   
   cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
   return 0;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    stack<pair<int,int>> st[N];
    
    for(int i = 0; i < n; ++i){
        int x, y;
        if(st[a[i]].empty()){
            x = 1;
            y = a[i] - x;
            if(x > 0 && y > 0){
                st[a[i]].push({x, y});
            }
            continue;
        }
        x = st[a[i]].top().first + 1;
        y = a[i] - x;
        if(x > 0 && y > 0){
            st[a[i]].push({x, y});
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < N; ++i){
        if(st[i].empty()) continue;
        cout << st[i].size() << endl;
        cnt += st[i].size();
    }
    cout << cnt << endl;
}