#include<bits/stdc++.h>
using namespace std;

int check (vector<pair<int,int>> &v,int n,int l,int r,int m){
	while(l<=r){
		int mid=l+(r-l)/2;
		 if(v[mid].first==m)return v[mid].second;
		 if(v[mid].first>m){
		 	r=mid-1;
		 }else{
		 	l=mid+1;
		 }
	}
	return -1;
}

int  main()
{
	int n,m;cin>>n>>m;
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		int k;cin>>k;
		v.push_back({k,i+1});
	}
	sort(v.begin(),v.end());
	int flag=true;
	for(int i=0;i<n;i++){
		int pos;
		if(m-v[i].first>=v[i].first){
			
			pos=check(v,n,i+1,n-1,m-v[i].first);
		}else{
			pos=check(v,n,0,i-1,m-v[i].first);
		}
		if(pos!=-1){
			cout<<v[i].second<<" "<<pos<<endl;
			flag=false;
			break;
		}
	}
	if(flag)cout<<"IMPOSSIBLE";
}


