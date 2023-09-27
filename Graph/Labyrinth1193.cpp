// Problem: Labyrinth
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1193
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
int n,m;
int r[4]={0,1,-1,0};
int c[4]={1,0,0,-1};
string a_="";
int fl=0;
signed  main()
{
	fastio;
	cin>>n>>m;
	vector<vector<char>> gr(n,vector<char> (m));
	vector<vector<int>> vis(n,vector<int> (m,1));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>gr[i][j];
		}
	}
	int x,y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			// cout<<gr[i][j];
			if(gr[i][j]=='A'){
				x=i;
				y=j;
			}
		}
		// cout<<endl;
	}
	queue<pair<int,int>> q;
	vis[x][y]=0;
	// cout<<x<<" "<<y<<endl;
	q.push({x,y});
	char mov[n][m];
	
	while(!q.empty()){
		auto p=q.front();
		int i=p.F;
		int j=p.S;
		// string s=p.S.S;
		q.pop();
		if(gr[i][j]=='B'){
			fl=1;
			while(1){
				a_.pb(mov[i][j]);
				if(a_[a_.size()-1]=='L'){
					j++;
				}else if(a_[a_.size()-1]=='R'){
					j--;
				}else if(a_[a_.size()-1]=='U'){
					i++;
				}else{
					i--;
				}
				if(i==x and j==y)break;
			}
			// a_=s;
			break;
		}
		else{
			for(int k=0;k<4;k++){
				if(r[k]+i>=0 and c[k]+j>=0 and r[k]+i<n and c[k]+j<m and gr[r[k]+i][c[k]+j]!='#' and vis[r[k]+i][c[k]+j]){
					vis[r[k]+i][c[k]+j]=0;
					if(r[k]==1){
						mov[r[k]+i][c[k]+j]=('D');
					}else if(r[k]==-1){
						mov[r[k]+i][c[k]+j]=('U');
					}else{
						if(c[k]==1){
							mov[r[k]+i][c[k]+j]=('R');
						}else{
							mov[r[k]+i][c[k]+j]=('L');
						}
					}
					q.push({r[k]+i,c[k]+j});
				}
			}
		}
	}
	if(a_.size()==0){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
		reverse(a_.begin(),a_.end());
		cout<<a_.size()<<endl;
		cout<<a_;
	}
	// cout<<a_<<endl;
    return 0;
}
//check options from back side 
//observe properly
//write on paper

