#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> coord;
map <int, coord> m;
void CREATESET(int x,int* P,int* rank) {
 P[x] = x;
 rank[x] = 0;
}
// A utility function to find set of an element i
// (uses path compression technique)
int find( int* parent ,int i)
{
    // find root and make root as parent of i (path compression)
    if (parent[i] != i)
       parent[i] = find( parent,parent[i]);
    return parent[i];
}
// A function that does union of two sets of x and y
// (uses union by rank)
void Union(int* parent,int* rank, int x, int y)
{
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    // Attach smaller rank tree under root of high rank tree
    // (Union by Rank)
    if (rank[xroot] < rank[yroot])
       parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    // If ranks are same, then make one as root and increment
    // its rank by one
    else
    {
        parent[yroot] = xroot;
       rank[xroot]++;
    }
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].first>>m[i].second;
	}
	int rank[n+1];
	int parent[n+1];
	int ans=0;
	rank[0]=0;
	parent[0]=0;
	int count=5;
	for(int i=1;i<=n;i++) CREATESET(i,parent,rank);	
	while(1){
		bool flag=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(find(parent,i)!=find(parent,j)){
					if(m[i].first==m[j].first || m[i].second==m[j].second) {
						Union(parent,rank,i,j);
					}
				}	
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) {
				if(find(parent,i)!=find(parent,j)){
					flag=1;
					ans++;
					Union(parent,rank,i,j);
					i=n+1;
					break;
				}
			}
		}
		if(flag==0) {cout<<ans; break;}	
	}
}
	
