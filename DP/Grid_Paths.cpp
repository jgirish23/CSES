#include<bits/stdc++.h>
using namespace std;

int vis[1000][1000];
int M=1e9+7;

int dfs(char **mat,int n,int i,int j)
{
	if(i>=n || j>=n || mat[i][j]=='*')return 0;
	if(i==n-1 and j==n-1)return 1;
	if(vis[i][j]!=-1)return vis[i][j];
	return vis[i][j]=(dfs(mat,n,i+1,j)%M+dfs(mat,n,i,j+1)%M)%M;
}

int  main()
{
	int n;cin>>n;
	char *mat[n	];
	for(int i = 0; i <n; i++)
   		mat[i] = new char[n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>mat[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			vis[i][j]=-1;
		}
	}
	int ans=dfs(mat,n,0,0);
	cout<<ans<<endl;
	// for(int i=0;i<n;i++){
		// for(int j=0;j<n;j++){
			// cout<<vis[i][j]<<" ";
		// }
		// cout<<endl;
	// }
    return 0;
}
//check options from back side 
//observe properly
//nearest stack
//write on paper

