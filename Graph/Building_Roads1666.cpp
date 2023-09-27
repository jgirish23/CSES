// Problem: Building Roads
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1666
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

int arr[100002],siz[100002]={1};
void par(int a){
	arr[a]=a;
}
int fpar(int a){
	if(arr[a]==a)return a;
	return arr[a]=fpar(arr[a]);
}
void make_set(int a,int b){
	a=fpar(a);
	b=fpar(b);
	if(par[a]!=par[b]){
		if(siz[a]>siz[b])swap(a,b);
		arr[a]=b;
		siz[b]+=siz[a];
		
	}
	
}

signed  main()
{
	fastio;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<n+1;i++)par(i);
	for(int i=0,a,b;i<m;i++){
		cin>>a>>b;
		make_set(a,b);
	}
	vi v;
	for(int i=1;i<n+1;i++){
		if(fpar(i)==i)v.pb(i);
	}
	cout<<v.size()-1<<endl;
	for(int i=1;i<v.size();i++){
		cout<<v[0]<<" "<<v[i]<<endl;
	}
	// for(auto j:v)cout<<j<<" ";
    return 0;
}
//check options from back side 
//observe properly
//write on paper

