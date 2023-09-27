#include<bits/stdc++.h>
using namespace std;


int  main()
{
	int n;cin>>n;
	long long a[n];
	for(auto &j:a)cin>>j;
	long long sum=0,ans=a[0];
	for(int i=0;i<n;i++){
		if(sum+a[i]>=0){
			sum+=a[i];
			ans=max(ans,sum);
		}else{
			sum=0;
			ans=max(ans,a[i]);
		}
	}
	cout<<ans;
}


