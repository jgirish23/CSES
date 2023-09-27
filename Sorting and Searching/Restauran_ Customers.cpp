#include<bits/stdc++.h>
using namespace std;


int  main()
{
	int n;cin>>n;
	vector<pair<int,int>> v;
	priority_queue <int, vector<int>, greater<int>> pq;
	for(int i=0,a,b;i<n;i++){
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.begin(),v.end());
	pq.push(v[0].second);
	int ans=1;
	for(int i=1;i<n;i++){
		while(pq.size() and pq.top()<v[i].first){
			pq.pop();
		}
		pq.push(v[i].second);
		ans=max(ans,(int)pq.size());
	}
	cout<<ans;
}


