#include<bits/stdc++.h>
using namespace std;

int M=1e9+7;

// vector<vector<int>> dp(1e5+1, vector<int> (101,-1)); //vector is taking X2 time that of array
int dp[100001][101];

bool is_safe(int a[],int n,int m, int pos){
	for(int i=max( pos, 1 );i<min( pos+2 , n ); i++){
		if(a[i]!=0 and abs(a[i]-a[i-1])>1){
			return true;
		}
	}
	return false;
}

int solve(int a[],int n,int m, int pos,int pre){
	if(pos==n){
		// for(int i=0;i<n;i++)cout<<a[i]<<" ";
		// cout<<endl;
		return 1;
	}
	
	if(dp[pos][pre]!=-1){
		return dp[pos][pre];
	}
	
	/*
		for the pre element find the pre - 1 , pre , pre + 1 because these will 
		give abs difference as 1
		
	*/
	
	long long ans=0;
	if(a[pos]==0){
		for(int i=max(pre-1,1);i<min(pre+3,m+1);i++){
			a[pos]=i;
			bool check=is_safe(a, n, m, pos);
			if(check){
				a[pos]=0;
				continue;
			}
			ans+=solve(a,n,m,pos+1,a[pos])%M;
			a[pos]=0;
		}
	}else{
		bool check=is_safe(a, n, m, pos);
		if(check){
			return 0;
		}
		ans+=solve(a,n,m,pos+1,a[pos])%M;
	}
	
	dp[pos][pre]=ans%M;	
	
	return ans%M;
}

int  main()
{
	int n,m;cin>>n>>m;
	int a[n];
	for(auto &j:a)cin>>j;
	bool flag=1;
	int pos=-1;
	memset(dp,-1,sizeof(dp));
	
	/* 
		Finding the 1st position where there is 0 value in array
	*/
	
	for(int i=0;i<n;i++){
		if(a[i]==0){
			pos=i;
			break;
		}
	}
	
	for(int i=1;i<n;i++){
		if(a[i]!=0 and a[i-1]!=0 and abs(a[i]-a[i-1])>1){
			flag=false;
			break;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	if(pos==-1){
		cout<<1;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		a[pos]=i;
		ans+=solve(a,n,m,pos,i)%M ;
		ans%=M;
	}
	cout<<ans<<endl;
}


