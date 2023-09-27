#include<bits/stdc++.h>
using namespace std;

int  main()
{
	int n,m;cin>>n>>m;
	int a[n],b[m];
	multiset<int> s;
	for(auto &j:a){cin>>j;s.insert(j);}
	for(auto &j:b)cin>>j;
	for(int i=0;i<m;i++){
		auto ele=s.upper_bound(b[i]);
		if(ele==s.begin()){
			cout<<-1<<endl;
		}else{
			
			ele--;
			cout<<*ele<<endl;
			s.erase(ele);
		}
	}
    return 0;
}
		

