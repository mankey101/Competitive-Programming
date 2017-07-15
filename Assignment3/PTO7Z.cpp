#include <bits/stdc++.h>
using namespace std;
int DFS(int i,bool * visited,vector<int>* adj,int *diameter){
	visited[i]=true;
	int max=0,max2=0;
	for(vector<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
		if(visited[*j]==false){
			int l=DFS(*j,visited,adj,diameter);
			if(l>max) {
				max2=max;
				max=l;
			}
			else if(l>max2){
				max2=l;
			}
		}
	}
	diameter[i]=max+max2;
	return max+1;
}	


int main(){
	int n;
	cin>>n;
	vector<int> adj[n+1];
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int diameter[n+1];
	bool visited[n+1];
	for(int i=1;i<=n;i++) visited[i]=false;
	int l=DFS(1,visited,adj,diameter);
	int temp=diameter[1];
	for(int i=2;i<=n;i++){
		if(temp<diameter[i]) temp=diameter[i];
	}
	cout<<temp;
}

		
	
	
	
	

