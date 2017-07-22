#include <bits/stdc++.h>
using namespace std;
 
void DFS(int i,int* level,vector<int>*adj,int *visited,int *coined){
	if(visited[i]) return ;
	bool flag=0;
	visited[i]=1;
	for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
		if(!visited[*it]){
			level[*it]=level[i]+1;
			flag=1;
			DFS(*it,level,adj,visited,coined);
		}
	}
	if(flag==0) coined[i]=1;
	bool flag2=1;
	for(vector<int>::iterator it=adj[i].begin();it!=adj[i].end();it++){
		if(level[*it]>level[i]){
			if(coined[*it]==0){flag2=0; break;}
		}
	}
	if(flag2==0) coined[i]=1;
}
 
 
 
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){cout<<-1<<endl; continue;}
		vector<int>adj[n+1];
		int visited[n+1];
		int coined[n+1];
		for(int i=0;i<=n;i++) visited[i]=0;
		for(int i=0;i<=n;i++) coined[i]=0;
		for(int i=0;i<n-1;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int level[n+1];
		level[1]=0;
		DFS(1,level,adj,visited,coined);
		int count=0;
		if(adj[1].size()==1) coined[1]=1;
		if(coined[1]==0){
			bool flag=0;
			for(vector<int>::iterator it=adj[1].begin();it!=adj[1].end();it++){
				if(adj[*it].size()==1) {flag=1; break;}
			}
			if(flag==1) coined[1]=1;
		}
		for(int i=1;i<=n;i++) {
			if(coined[i]==1) count++;
		}
 
		//for(int i=1;i<=n;i++) cout<<coined[i]<<" ";
		//cout<<endl;
		//for(int i=1;i<=n;i++) cout<<level[i]<<" ";
		//cout<<endl;
		cout<<count<<endl;
		
		
	}
}	
 
