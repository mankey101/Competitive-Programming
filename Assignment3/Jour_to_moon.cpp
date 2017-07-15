#include <bits/stdc++.h>
using namespace std;
bool UNDIR=1;
int time_curr;
int connected;
int t;
void DFS(int i,list<int> *adj,int* visited,int* time,int* county){
	county[t]++;
	visited[i]=0;
	time[i]=time_curr;
	time_curr++;
	for(list<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		if(visited[*j]==-1) DFS(*j,adj,visited,time,county);
		//else if(visited[*j]==1) cout<<"Cycle found "<<i<<" "<<*j<<endl;
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
	int visited[V];
	int time[V];
	for(int i=0;i<V;i++){
		visited[i]=-1;
		time[i]=-1;
	}
	int county[V];
	for(int i=0;i<V;i++) county[i]=0;
	for(int i=0;i<V;i++){
		if(visited[i]==-1){
			DFS(i,adj,visited,time,county);
			connected++;
			t++;
		}
	}
	long long ans=0;
	sort(county,county+V);
	long long int summ;
	for(int i=V-1;i>=0;i--){
	if(county[i]>1){
		summ+=county[i];	
		for(int j=i-1;j>=0;j--){
			if(county[j]>1) ans=ans + county[i]*county[j];
			else break;
		}
	}
	else{
		int tt;
		for(tt=0;tt<V;tt++)if(county[tt]==1) break;
		 long long ones =i-tt+1;
		if(ones>0){
			 ans+=ones*(ones-1)/2;
			ans+=(summ*ones);
		}		
		break;	
	}
	}
	cout<<ans;
}
		
