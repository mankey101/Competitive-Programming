#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<int> adj[n+1];
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	int visited[n+1];
	for(int i=1;i<=n;i++) visited[i]=-1;
	vector<int>connected[n];
	int a=-1;
	for(int i=1;i<=n;i++){
		int count=0;
		queue<int> q;
		if(visited[i]!=1){
			 q.push(i);	
			a++;
			connected[a].push_back(i);
		}
		visited[i]=1;
		while(!q.empty()){
			int t=q.front();
			q.pop();
			for(vector<int>::iterator j=adj[t].begin();j!=adj[t].end();++j){
				if(visited[*j]==-1){
					visited[*j]=1;
					q.push(*j);
					connected[a].push_back(*j);
				}
			}
		}
	}
	int i=0;
	for(int i=0;i<n;i++) {
		if(connected[i].size()==0) break;
		if(connected[i].size()>3) {
			cout<<-1;
			return 0;
		}
	}
	int size[3];
	for(int i=0;i<3;i++) size[i]=0;
	for(int i=0;i<n;i++){
		if(connected[i].size()==0) break;
		size[connected[i].size()-1]++;
	}
	if(size[0]<size[1]){
		cout<<-1;
		return 0;
	}

	bool dekh[n+1];
	for(int i=1;i<=n;i++) dekh[i]=false;
	for(int i=0;i<n;i++){
		if(connected[i].empty()) break;
		if(connected[i].size()==3 || connected[i].size()==0){
			for(vector<int>::iterator j=connected[i].begin();j!=connected[i].end();j++){
				cout<<*j<<" ";
			}
			cout<<endl;
		}
		else if(connected[i].size()==2){
			vector<int>::iterator j=connected[i].begin();
			cout<<*j<<" "<<*(j+1);
			for(int k=0;k<n;k++){
				 if(connected[k].size()==1){
					if(dekh[connected[k][0]]==false) {
						cout<<" "<<connected[k][0];
						dekh[connected[k][0]]=true;
						cout<<endl;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(connected[i].size()==1 && dekh[connected[i][0]]==false){
			for(int j=i+1;j<n;j++){
				if(connected[j].size()==0) break;
				if(connected[j].size()==1 && dekh[connected[j][0]]==false){
					for(int k=j+1;k<n;k++){
						if(connected[k].size()==0) break;
						if(connected[k].size()==1 && dekh[connected[k][0]]==false){
							cout<<connected[j][0]<<" "<<connected[i][0]<<" "<<connected[k][0]<<endl;
							dekh[connected[i][0]]=true;
							dekh[connected[j][0]]=true;
							dekh[connected[k][0]]=true;
							k=n;
							j=n;
						}
					}
				}
			}
		}
	}						
}

