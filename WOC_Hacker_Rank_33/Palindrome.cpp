#include <bits/stdc++.h>
using namespace std;
void CREATESET(int x,int* P,int* rank) {
 P[x] = x;
 rank[x] = 0;
}
// A utility function to find set of an element i
// (uses path compression technique)
int find( int*parent ,int i)
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
int max (int x, int y) { return (x > y)? x : y; }
int lps(int *str,int m,int *P)
{
   int i, j, cl;
   int L[m][m]; 
   for (i = 0; i < m; i++)
      L[i][i] = 1;
 
    for (cl=2; cl<=m; cl++)
    {
        for (i=0; i<m-cl+1; i++)
        {
            j = i+cl-1;
            if (find(P,str[i])==find(P,str[j])  && cl == 2)
               L[i][j] = 2;
            else if (find(P,str[i])==find(P,str[j]))
               L[i][j] = L[i+1][j-1] + 2;
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]);
        }
    }
 
    return L[0][m-1];
}

int main(){
	int n,k,m;
	cin>>n>>k>>m;
	int P[n+1];
	int rank[n+1];
	P[0]=0;
	rank[0]=0;
	for(int i=1;i<=n;i++) CREATESET(i,P,rank);
	for(int i=0;i<k;i++){
		int t,b;
		cin>>t>>b;
		 Union(P,rank,t,b);
	}
	int str[m];
	for(int i=0;i<m;i++){
		 cin>>str[i];
	}
	cout<<lps(str,m,P);	
}

	
