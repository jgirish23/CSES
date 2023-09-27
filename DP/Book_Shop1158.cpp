// Problem: Book Shop
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1158
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
int n,m;
int dp[1000][100001];
// int f(int n,int m,int a[],int b[]){
	// if(n<0)return 0;
	// if(m==0)return 0;
	// int pick=0;
	// if(dp[n][m])return dp[n][m];
	// if(m>=a[n]){
		// pick=b[n]+f(n-1,m-a[n],a,b);
	// }
	// int npick=f(n-1,m,a,b);
	// return dp[n][m]=max(pick,npick);
// }

signed  main()
{
	fastio;
	cin>>n>>m;
	int a[n],b[n];
	for(auto &i:a)cin>> i;
	for(auto &i:b)cin>> i;
	//recurrsive
	
	// int ans=f(n-1,m,a,b);
	// cout<<ans;
	
	int pre[100001]={0},curr[100001]={0};
	for(int i=0;i<m+1;i++){
		if(i>=a[0])pre[i]=b[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<m+1;j++){
			int pick =0;
			if(j>=a[i]){
				pick=b[i]+pre[j-a[i]];
			}
			int npick=pre[j];
			curr[j]=max(pick,npick);
		}
		for(int j=0;j<m+1;j++)pre[j]=curr[j];
	}
	cout<<curr[m];
    return 0;
}
//check options from back side 
//observe properly
//write on paper

