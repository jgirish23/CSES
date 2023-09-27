// Problem: Money Sums
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1745
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

set<int> ans;
void f(int n,int v[],int sum){
	if(n<0 ){
		if(sum){
			ans.insert(sum);
			// cout<<sum<<" ";
		}
		return;
	}
	f(n-1,v,sum+v[n]);
	f(n-1,v,sum);
}

signed  main()
{
	fastio;
	int n;cin>>n;
	int v[n];
	for(auto &i:v)cin>>i;
	// recurrsive
	// f(n-1,v,0);
	int dp[100001]={0};
	dp[0]=1;
	for(int j=0;j<n;j++){
		for(int i=100000;i>=0;i--){
			if(i-v[j]>=0)dp[i]|=dp[i-v[j]];
		}
	}
	// for(auto h:dp)cout<<h<<" ";
	for(int i=1;i<100001;i++)if(dp[i])ans.insert(i);
	cout<<ans.size()<<endl;
	for(auto h:ans)cout<<h<<" ";

    return 0;
}
//check options from back side 
//observe properly
//write on paper

