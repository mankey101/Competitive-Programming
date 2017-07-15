#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int cnt=0;
ll x;
int n,m;
bool visited[110000];
vector<int>adj[110000];
vector<ll>len[110000];

void DFS(int i,int cnd){
	visited[i]=true;
	int pseudoc=0;
	for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		cnd=0;
		if(pseudoc==0) max=0;
		pseudoc++;
		int ind=j-adj[i].begin();
		if(visited[*j]==false){
			if(len[i][ind]>max) max=len[i][ind];	
			if(max==x) cnt+=cnd;
			if(max>x) cnd=0;
			else cnd++;
		 	
			DFS(*j,cnd);
		}
	}
}	




int main(){
	cin>>n>>m>>x;
	for(int i=0;i<m;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		adj[a].push_back(b);
		adj[b].push_back(a);
		len[a].push_back(c);
		len[b].push_back(c);
	}
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			int cnd=0;
		       	DFS(i,cnd);
	}
	cout<<cnt;
	
}


