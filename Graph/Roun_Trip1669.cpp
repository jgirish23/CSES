// Problem: Round Trip
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1669
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
vector<int> graph[100001],vis(100001),ans,p(100001,0);
int sp,sc;
bool dfs(int i,int par){
	vis[i]=1;
	p[i]=par;
	for(auto j:graph[i]){
		if(par==j)continue;
		if(vis[j] and par!=j){
			sc=j;
			sp=i;
			return true;
		}
		if(!vis[j]){
			if(dfs(j,i)){
				cout<<j<<" ";
				return true;
			}
		}
	}
	return false;
}

signed  main()
{
	fastio;
	int n,m,f=0;cin>>n>>m;
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	for(int i=1;i<n+1;i++){
		if(vis[i]==0){
			if(dfs(i,0)){
				f=1; 
				break;	
			}
			
		}
	}
	if(f==0){
		cout<<"IMPOSSIBLE";
		return 0;
	}
	// for(int i=0;i<n+1;i++)cout<<p[i]<<" ";
	cout<<endl;
	int j=sp;
	ans.pb(sp);
	while(j!=sc){
		ans.pb(p[j]);
		j=p[j];
	}
	ans.pb(sp);
	// cout<<ans.size()<<endl;
	// for(auto k:ans)cout<<k<<" ";
    return 0;
}
//check options from back side 
//observe properly
//write on paper

