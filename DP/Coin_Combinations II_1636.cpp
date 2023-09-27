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
const int M=1e9+7;
	vector<int> dp(1000002);
signed  main()
{
	fastio;
	int n,m;
	cin>>n>>m;
	int v[n];
	for(int i=0;i<n;i++)cin>>v[i];
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=1;j<m+1;j++){
			if(j-v[i]>=0){
				dp[j]=(dp[j]+dp[j-v[i]])%M;
			}
		}
	}
	// for(auto j:dp)cout<<j<<" ";
	// cout<<endl;
	cout<<dp[m];
    return 0;
}