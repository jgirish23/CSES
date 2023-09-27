// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
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
	int n,m;cin>>n>>m;
	vector<int> graph[n+1],par(n+1,0);
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		graph[u].pb(v);
		graph[v].pb(u);
	}
	queue<pair<int,int>> q;
	q.push({1,0});
	int fl=0;
	par[1]=1;
	while(!q.empty()){
		auto p=q.front();
		int i=p.F;
		int ct=p.S;
		q.pop();
		if(i==n){
			fl=1;
			break;
		}
		for(auto k:graph[i]){
			if(par[k]==0){
				q.push({k,ct+1});
				par[k]=i;
			}
		}
	}
	if(fl){
		vector<int> v;
		while(n!=1){
			v.pb(n);
			n=par[n];
		}
		v.pb(1);
		reverse(all(v));
		cout<<v.size()<<endl;
		for(auto j:v)cout<<j<<" ";
	}else{
		cout<<"IMPOSSIBLE"<<endl;
	}
    return 0;
}
//check options from back side 
//observe properly
//write on paper

