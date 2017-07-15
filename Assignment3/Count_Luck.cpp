#include <bits/stdc++.h>
using namespace std;
typedef map<int,pair< pair<int,int>, char> > vert;
int tc;
int wand[100000][20];
int m[20];
int flag[20];
int INF= 100000;
int level[100000][20];
void DFS(int i, bool* visited, vector<int>* adj,int final,int k){
	int o=0;
	if(i==final){	
		flag[tc]=1;
		int ty=0;
		while(wand[ty][tc]==0 && ty<INF) ty++;
		if(ty==INF){
			if(k==0) cout<<"Impressed\n";
			else cout<<"Oops!\n";
			return ;
		}
		while(wand[ty][tc]!=0) ty++; 
		if(wand[ty-1][tc]==k){
			cout<<"Impressed\n";
		}
		else cout<<"Oops!\n";
		return ;
	}
	visited[i]=true;
	for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		if(visited[*j]==false){
			m[tc]=level[*j][tc];
			wand[m[tc]][tc]=0;
		//	cout<<"*j "<<*j<<" "<<"M "<<m<<endl;
			if(adj[*j].size()>2 && *j!=final) wand[m[tc]][tc]=wand[m[tc]-1][tc]+1;
			else wand[m[tc]][tc]=wand[m[tc]-1][tc];
			DFS(*j,visited,adj,final,k);
			if(flag[tc]==1) break;
		}
	}
}	 

int main(){
	int t;
	cin>>t;
	for(int ff=0;ff<t;ff++){
		int n,m;
		cin>>n>>m;
		char f[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) cin>>f[i][j];
		}
		int k;
		cin>>k;
		vert vertex;
		int t=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				vertex[t].first.first=i;
				vertex[t].first.second=j;
				vertex[t++].second=f[i][j];
			}
		}
		int si,sj;
		bool flag=1;
		for(si=0;si<n;si++){
			for(sj=0;sj<m;sj++){
				 if(f[si][sj]=='M'){
					flag=0;
					 break;
				}
			}
			if(flag==0) break;
		}
		flag=1;
		int fi,fj;
		for(fi=0;fi<n;fi++){
			for(fj=0;fj<m;fj++){
				 if(f[fi][fj]=='*'){
					 flag=0;
					 break;
				}
			}
			if(flag==0) break;
		}
		int start=si*m+sj+1;
		int final=fi*m+fj+1;
		vector < int > adj[n*m+1];
		int tt=1;
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++){
				if(f[i][j]=='.' || f[i][j]=='*' || f[i][j]=='M'){
					if (i+1<n && (f[i+1][j]=='.' || f[i+1][j]=='*' || f[i+1][j]=='M')) adj[tt].push_back(tt+m); 
					if (i-1>=0 && (f[i-1][j]=='.' || f[i-1][j]=='*'|| f[i-1][j]=='M'))adj[tt].push_back(tt-m);
					if(j+1<m && (f[i][j+1]=='.' || f[i][j+1]=='*' || f[i][j+1]=='M')) adj[tt].push_back(tt+1) ;
					if(j-1>=0 && (f[i][j-1]=='.' || f[i][j-1]=='*'|| f[i][j-1]=='M' )) adj[tt].push_back(tt-1);	
				}
				tt++;
			}
		}
		bool visited[m*n+1],visit[m*n+1];
		for(int i=1;i<=m*n;i++) {
			visited[i]=false;
			visit[i]=false;
		}

		queue<int> q;
		q.push(start);
		while(!q.empty()){
			int t=q.front();
			visit[t]=true;
			q.pop();
			for(vector<int>::iterator it=adj[t].begin();it!=adj[t].end();it++){
				if(visit[*it]==false){
					level[*it][tc]=level[t][tc]+1;
					q.push(*it);
					visit[*it]=true;
				}
			}
		}
		if(adj[start].size()>1) wand[0][tc]=1;
		DFS(start,visited,adj,final,k);	
		tc++;	
	}
	
}
		
		
