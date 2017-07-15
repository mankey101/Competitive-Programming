#include <bits/stdc++.h>
using namespace std;
bool UNDIR=1;
int time_curr;
int connected;
void DFS(int i,list<int> *adj,int* visited,int* time){
	visited[i]=0;
	time[i]=time_curr;
	time_curr++;
	for(list<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		if(visited[*j]==-1) DFS(*j,adj,visited,time);
		else if(visited[*j]==1) cout<<"Cycle found "<<i<<" "<<*j<<endl;
	}
	visited[i]=1;
}
		
	



int main(){
	int V;
	int E;
	cin>>V>>E;
	list<int>adj[V+1];
	for(int i=0;i<E;i++) {
		int source,dest;
		cin>>source>>dest;
		adj[source].push_back(dest);
		if(UNDIR) adj[dest].push_back(source);
	}
	int visited[V+1];
	int time[V+1];
	for(int i=1;i<=V;i++){
		visited[i]=-1;
		time[i]=-1;
	}
	for(int i=1;i<=V;i++){
		if(visited[i]==-1){
			DFS(i,adj,visited,time);
			connected++;
		}
	}
	for(int i=1;i<=V;i++) cout<<time[i]<<endl; 
	cout<<connected;
}
		
