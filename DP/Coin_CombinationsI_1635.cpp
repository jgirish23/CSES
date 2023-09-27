// Problem: Coin Combinations I
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1635
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
int M=1e9+7;
int f(int m,vector<int> &v,vector<int> &dp){
	if(m==0) return 1;
	if(m<0){
		return 0;
	}
	int pick=0;
	if(dp[m]!=-1)return dp[m];
	for(int i=0;i<v.size();i++){
		// if(m>=v[i]){
			pick+=f(m-v[i],v,dp);
		// }
	}
	// int npick=f(m,v,dp);
	return dp[m]=pick%M;
	
}

signed  main()
{
	fastio;
	int n,m;cin>>n>>m;
	vector<long long> v(n);
	vector<long long> dp(m+1,0);
	for(int i=0;i<n;i++)cin>>v[i];
	// for(auto j:v)cout<<j<<" ";
	// cout<<endl;
	// int ans=f(m,v,dp);
	// cout<<ans%M<<endl;
	for(int i=0;i<n;i++)dp[i]=1;
	// for(i)
	for(int i=0;i<n;i++){
		int pick=0;
		for(int j=0;j<=m;j++){
			if(j>=v[i])dp[j]+=dp[j-v[i]];
		}
		// dp[i]=pick%M;
	}
	cout<<dp[m]<<endl;
    return 0;
}
//can remove
//observe properly
//write on paper

