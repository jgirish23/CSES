// Problem: Shortest Routes I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1671
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
typedef long long ll;
#define int ll
typedef vector<int> vi;

signed  main()
{
	fastio;
	int n,m;cin>>n>>m;
	vector<pair<int,int>> graph[n+1];
	for(int i=0,a,b,c;i<m;i++){
		cin>>a>>b>>c;
		// if(a>b)swap(a,b);
		graph[a].pb({b,c});
		// graph[b].pb({a,c});
	}
	queue<pair<int,pair<int,int>>> q;
	vi dis(n+1,INT_MAX);
	dis[1]=0;
	for(auto j:graph[1]){
		q.push({1,j});
	}
	int ct=0;
	while(!q.empty()){
		auto k=q.front();
		int p=k.F;
		int u=k.S.F;
		int w=k.S.S;
		q.pop();
		if(dis[u]>w+dis[p]){
			dis[u]=min(dis[u],w+dis[p]);
			for(auto j:graph[u]){
				q.push({u,j});
			}
		}
		ct++;
		// if(ct==1000)break;
	}
	for(int i=1;i<n+1;i++)cout<<dis[i]<<" ";
    return 0;
}
//check options from back side 
//observe properly
//write on paper

