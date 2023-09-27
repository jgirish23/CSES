// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define all(v) v.begin(),v.end()
#define F first
#define S second
typedef vector<vector<long long>> vii;
typedef vector<int> vi;
typedef long long ll;
#define int ll

signed  main()
{
	fastio;
	int n,m,f=0;cin>>n>>m;
	vector<int> graph[n+1],hsh(n+1,0),vis(n+1);
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	deque<int> q;
	for(int i=1;i<n+1;i++)q.push_back(i);
	while(!q.empty()){
		int ch=q.front();
		q.pop_front();
		vis[ch]++;
		for(auto j:graph[ch]){
			if(vis[j]==0){
				q.push_front(j);
				vis[j]++;
				hsh[j]=((hsh[ch]+1)%2);
			}else{
				if(hsh[ch]==hsh[j]){
					f=1;
					break;
				}
			}
		}
		if(f)break;
	}
	if(f){
		cout<<"IMPOSSIBLE"<<endl;
	}else{
		for(int i=1;i<n+1;i++){
			cout<<hsh[i]+1<<" ";
		}
	}
    return 0;
}
//check options from back side 
//observe properly
//write on paper

