#include<bits/stdc++.h>
using namespace std;

int  main()
{
	int n;cin>>n;
	vector<pair<int,int>> v;
	for(int i=0,a,b;i<n;i++){
		cin>>a>>b;
		v.push_back({b,a});
	}
	sort(v.begin(),v.end());
	int pre=v[0].first;
	int ct=1,ans=1;
	for(int i=1;i<n;i++){
		if(pre<=v[i].second){
			// pre=v[i].second;
			pre=v[i].first;
			ct++;
			ans=max(ct,ans);
		}
	}
	cout<<ans;
}


