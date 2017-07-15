#include <bits/stdc++.h>
using namespace std;

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
	int n,m;
	cin>>n>>m;
	vector<int> adj[n];
	bool flag=0;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		if(t!=0) flag=1;	
		for(int j=0;j<t;j++) {
			int x;
			cin>>x;
			adj[i].push_back(x);
		}
	}
	if(flag==0){
		cout<<n;
		return 0;
	}
	int coun=0;
	int parent[n],rank[n];
	for(int i=0;i<n;i++) CREATESET(i,parent,rank);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<adj[i].size();k++){
				for(int l=0;l<adj[j].size();l++){
					if(adj[i][k]==adj[j][l]){
						Union(parent,rank,i,j);
						break;
					}
				}
			}
		}
	}
	int count=0;
/*	for(int i=0;i<n;i++){
		if(find(parent,i)==i && adj[i].size()==0) count++;
	}*/
	set<int> temp;
	for(int i=0;i<n;i++) temp.insert(find(parent,i));
	int conn=temp.size()-1;
	cout<<conn+count;	 
}
