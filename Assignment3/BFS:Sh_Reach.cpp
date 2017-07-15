#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int n,m;
		cin>>n>>m;
		vector<int>adj[n+1];
		for(int i=0;i<m;i++){
			int x,y;
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		int s;
		bool visited[n+1];
		for(int i=1;i<=n;i++) visited[i]=false;
		cin>>s;
		queue<int>st;
		int level[n+1];
		for(int i=1;i<=n;i++) level[i]=-1;
		level[s]=0;
		st.push(s);
		while(!st.empty()){
			int t=st.front();
			st.pop();
			visited[t]=true;
			for(vector<int>::iterator it=adj[t].begin();it!=adj[t].end();it++){
				if(visited[*it]==false){
					visited[*it]=true;
					st.push(*it);
					level[*it]=level[t]+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(level[i]==0) continue;
			if(level[i]!=-1) cout<<level[i]*6<<" ";
			else cout<<-1<<" ";
		}
		cout<<endl;
	}
}

				
