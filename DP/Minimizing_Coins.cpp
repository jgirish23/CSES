#include<bits/stdc++.h>
using namespace std;


int dp[1000001];
int solve(int a[],int n,int x,int ct){
	if(x==0){
		return 0;
	}
	int k=INT_MAX;
	if(dp[x]!=-1)return dp[x];
	for(int i=0;i<n;i++){
		if(a[i]<=x){
			int temp=solve(a,n,x-a[i],ct+1);
			if(temp!=INT_MAX and temp+1<k){
				k=temp+1;
			}
		}
	}
	dp[x]=k;
	return k;
}


int  main()
{
	int n,x;cin>>n>>x;
	int a[n];
	for(auto &j:a)cin>>j;
	
	for(auto &j:dp)j=-1;
	int ans=solve(a,n,x,0);
	// for(auto &j:dp)cout<<j<<" ";
	ans==INT_MAX ? cout<<-1:cout<<ans;
    return 0;
}


