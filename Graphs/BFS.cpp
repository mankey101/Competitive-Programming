#include <bits/stdc++.h>
using namespace std;
bool UNDIR=1;
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
        int distance[V+1];
        for(int i=1;i<=V;i++){
                visited[i]=-1;
                distance[i]=0;
        }
	for(int i=1;i<=V;i++){
		if(visited[i]==-1){
			visited[i]=0;
			for(list<int>::iterator j=adj[i].begin();j!=adj[i].end();j++){
				if(visited[*j]==0){
					visited[*j]=0;
					distance[i]=distance[*j]+1;
				}
				else if(visited[*j]==-1){
					visited[*j]=0;
					distance[*j]=distance[i]+1;
				}
			}
			visited[i]=1;
		}
	}
	for(int i=1;i<=V;i++) cout<<distance[i]<<endl;
}	
