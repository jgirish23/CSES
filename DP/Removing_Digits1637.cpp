// Problem: Removing Digits
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1637
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

int f(int s,vector<int> &dp){
	if(s<0)return INT_MAX;
	// cout<<s<<endl;
	if(s==0)return 0;
	string st=to_string(s);
	if(dp[s]!=INT_MAX)return dp[s];
	int l=INT_MAX;
	for(int i=0;i<st.size();i++){
		if(st[i]!='0'){
			int ct=f(s-(st[i]-'0'),dp);
			// if(dp[s]!=INT_MAX){
				// dp[s]=min(dp[s-(st[i]-'0')],dp[s]);
			// }else{
				dp[s]=min(min(ct,dp[s-(st[i]-'0')])+1,dp[s]);
			// }
		}
	}
	// 	dp[s-(st[i]-'0')]
	// dp[s]=l;
	return dp[s];
}

signed  main()
{
	fastio;
	int s;cin>>s;
	vector<int> dp(s+1,INT_MAX);
	cout <<f(s,dp)<<endl;
	// for(int i=0;i<=s;i++)cout<<i<<": "<<dp[i]<<endl;
	// cou
    return 0;
}
//check options from back side 
//observe properly
//write on paper

