#include<bits/stdc++.h>
using namespace std;

int sol(string s,char c){
	map<int,int> m;
	for(auto j:s){
		m[j]++;
	}
	cout<<m[c];
	return m[c];
}

int  main()
{
	int n;cin>>n;
	long long a[n];
	for(auto &j:a)cin>>j;
	sort(a,a+n);
	int mid=a[n/2];
	long long ans=0;
	for(int i=0;i<n;i++){
		ans+=abs(a[i]-mid);
	}
	cout<<ans;
    return 0;
}


