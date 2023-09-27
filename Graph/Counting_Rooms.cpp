#include<bits/stdc++.h>
using namespace std;

int x[]={0,1,-1,0};
int y[]={1,0,0,-1};

void dfs(int n,int m,vector<vector<char>> &mat,vector<vector<int>> &vis,int i,int j){
	vis[i][j]=1;
	for(int k=0;k<4;k++){
		int n_x=i+x[k];
		int n_y=j+y[k];
		if(n_x>=0 and n_x<n and n_y>=0 and n_y<m and !vis[n_x][n_y] and mat[n_x][n_y]=='.'){
			// return ;
			dfs(n,m,mat,vis,n_x,n_y);
			
		}
	}
}

int  main()
{
	int n,m;cin>>n>>m;
	vector<vector<char>> mat(n,vector<char> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
		}
	}
	
	vector<vector<int>> vis(n,vector<int> (m,0));
	
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j] and mat[i][j]=='.'){
				cnt++;
				dfs(n,m,mat,vis,i,j);
			}
		}
	}
	cout<<cnt;
    return 0;
}


