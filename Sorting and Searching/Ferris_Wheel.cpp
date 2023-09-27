#include<bits/stdc++.h>
using namespace std;


int  main()
{
	int n,x;cin>>n>>x;
	int a[n];
	for(auto &j:a)cin>>j;
	sort(a,a+n);
	int cnt=n;
	int i=0,j=n-1;
	while(i<j){
		if(a[i]+a[j]<=x){
			cnt--;
			i++;
			j--;
		}else{
			j--;
		}
	}
	cout<<cnt;
    return 0;
}


