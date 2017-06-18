#include <bits/stdc++.h>
using namespace std;
void addEdge(vector<int> adj[], int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DFS2(vector<int> adj[],int x,bool visited[],int n,vector<int> adjj[],int xo){
	for(int i=0;i<adj[xo].size();i++){
		if(visited[adj[xo][i]]==false){
			adjj[x].push_back(adj[xo][i]);
			visited[adj[xo][i]]=true;
			DFS2(adj,x,visited,n,adjj,adj[xo][i]);
		}
	}
}	
void DFS(vector<int>adj[],int n,vector<int> adjj[]){
	int count=0;
		for(int x=1;x<=n;x++){
			bool visited[n+1];
			memset(visited,false,(n+1)*sizeof(bool));
			DFS2(adj,x,visited,n,adjj,x);
		}
	
}
int main(){
	int counti=0;
	int n,m;
	cin>>n>>m;
	vector<int>adjj[n+1];
	vector<int>adj[n+1];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		 addEdge(adj,u,v);
	}
	DFS(adj,n,adjj);
	for(int i=1;i<=n;i++) {
		int j=0;
		while(j!=adjj[i].size()) cout<<adjj[i][j++]<<" ";
		cout<<endl;
	}
	return 0;
}	
