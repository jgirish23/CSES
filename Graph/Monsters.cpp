#include<bits/stdc++.h>
using namespace std;

int x[]={0,1,-1,0};
int y[]={1,0,0,-1};
map<int,char> dir={{0,'R'},{1,'D'},{2,'U'},{3,'L'}};
// dir[0]='R';
// dir[1]='D';
// dir[2]='U';
// dir[3]='L';
string path="",ans="";
bool flag=false;
void dfs(int i,int j,vector<vector<int>> &dist,vector<vector<char>> &mat,int n,int m){
	if(i==n-1 || i==0 || j==m-1 || j==0){
		ans=path;
		flag=true;
		return;
	}
	for(int k=0;k<4;k++){
		int n_x=i+x[k];
		int n_y=j+y[k];
		if(n_x>=0 and n_x<n and n_y>=0 and n_y<m and mat[n_x][n_y]!='#' and dist[i][j]+1<dist[n_x][n_y]){
			path.push_back(dir[k]);
			dist[n_x][n_y]=dist[i][j]+1;
			dfs(n_x,n_y,dist,mat,n,m);
			path.pop_back();
		}
	}
}
int  main()
{
	int n,m;cin>>n>>m;
	vector<vector<char>> mat(n,vector<char>(m));
	vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
	queue<pair<int,int>> q;
	
	int s_x,s_y;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mat[i][j];
			if(mat[i][j]=='M'){
				dist[i][j]=0;
				q.push({i,j});
			}
			else if(mat[i][j]=='A'){
				// dist[i][j]=2;
				s_x=i;
				s_y=j;
			}
		}
	}
	
	 
	 /*
	 	Mark shortest distance to all nodes from the monsters 
	 */
	 while(!q.empty()){
	 	int c_x=q.front().first;
	 	int c_y=q.front().second;
	 	q.pop();
	 	for(int i=0;i<4;i++){
	 		int n_x=c_x+x[i];
	 		int n_y=c_y+y[i];
	 		if(n_x>=0 and n_x<n and n_y>=0 and n_y<m and mat[n_x][n_y]!='#' and dist[c_x][c_y]+1<dist[n_x][n_y]){
	 			dist[n_x][n_y]=dist[c_x][c_y]+1;
	 			q.push({n_x,n_y});
	 		}
	 	}
	 }
	 
	 /*
	 	check if shortest distance to a particular node is less then the monsters distance 
	 */
	 dist[s_x][s_y]=0;
	 dfs(s_x,s_y,dist,mat,n,m);
	  
	flag?cout<<"YES":cout<<"NO";
	if(flag){
		cout<<endl;
		cout<<ans.size()<<endl;
		cout<<ans;
		
	}
}
//check options from back side 
//observe properly
//nearest stack
//write on paper

