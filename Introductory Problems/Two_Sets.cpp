//Problem: Two Sets
//Contest: CSES - CSES Problem Set
//URL: https://cses.fi/problemset/task/1092
//Memory Limit: 512 MB
//Time Limit: 1000 ms

#include<bits/stdc++.h>
using namespace std;


int  main()
{
	
	int n;cin>>n;
	
	if((n*(n+1))%4==0){
		vector<int> f,s;
		int cnt=n/4;
		int i=1,r=n;
		if((n+1)%4==0){
			cnt=(n+1)/4;
			cnt--;
			i=1;
			r=n-1;
			f.push_back(n);
		}
		while(cnt--){
			f.push_back(i);
			f.push_back(r);
			i++;
			r--;
		}
		while(i<=r){
			s.push_back(i);
			i++;
		}
		cout<<"YES"<<endl;
		cout<<f.size()<<endl;
		for(auto j:f)cout<<j<<" ";
		cout<<endl;
		cout<<s.size()<<endl;
		for(auto j:s)cout<<j<<" ";
	}else{
		cout<<"NO";
	}
    return 0;
}
//check options from back side 
//observe properly
//nearest stack
//write on paper

