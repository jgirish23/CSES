// Problem: Dice Combinations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1633
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
const int N=1e9+7;
int dp[1000000+2];
 
int f(int n){
	if(n==0)return 1;
	int ans=0,l=0;
	// if(n<0)return 0;
	if(dp[n]!=-1)return dp[n];
	for(int i=1;i<=6;i++){
		
		if(n>=i){
			ans+=f(n-i)%N;
			ans%=N;
			// l=max(ans,l)%N;
			// dp[n][i]=ans;
		}
		
	}
	dp[n]=ans%N;
	return dp[n];
}
 
int  main()
{
	fastio;
	int n;cin>>n;
	// memset(dp,-1,sizeof(dp));
	// cout<<f(n)<<endl;
	int dp[n+1]={0};
	dp[0]=1;
	// dp[1]=1;
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=1;j<7;j++){
			if(i-j>=0){
				ans+=dp[i-j];
				ans%=N;
			}
		}
		dp[i]=ans%N;
	}
	cout<<dp[n]<<endl;
	// for(int i=1;i<=n;i++){
		// // for(int j=1;j<7;j++)
		// cout<<dp[i]<<" ";
		// cout<<endl;
	// }
    return 0;
}
//can remove
//observe properly
//write on paper