#include <bits/stdc++.h>
using namespace std;
void DFSpre(int *tree,int *pre,int n,int size,int i,int *j){
	if(i>=size || (*j)>=n) return ; 
	tree[i]=pre[(*j)++];
	int k,l;
	k=i*2+1;
	l=i*2+2;
	DFSpre(tree,pre,n,size,k,j);
	DFSpre(tree,pre,n,size,l,j);
	return;
}

void DFSpost(int *tree,int *post,int n,int size,int i,int *j,int* tree1){
	if(i>=size || (*j)>=n || tree1[i]==0) return ;
	int k=2*i+1;
	int l=2*i+2;
	DFSpost(tree,post,n,size,k,j,tree1);
	DFSpost(tree,post,n,size,l,j,tree1);
	tree[i]=post[(*j)++];
	return ;
}

void DFSin(int *tree,int *in,int n,int size,int i,int *j,int* tree1){
	if(i>=size || (*j)>=n || tree1[i]==0) return ;
	int k=2*i+1;
	int l=2*i+2;
	DFSin(tree,in,n,size,k,j,tree1);
	tree[i]=in[(*j)++];	
	cout<<"i: "<<i<<" j: "<<*j-1<<endl;
	DFSin(tree,in,n,size,l,j,tree1);
	return ;
}
	



int main(){
	int n;
	cin>>n;
	int pre[n],post[n],in[n];
	for(int i=0;i<n;i++) cin>>pre[i];
	for(int i=0;i<n;i++) cin>>post[i];
	for(int i=0;i<n;i++) cin>>in[i];
	double temp=log(n);
	double bas=log(2);
	int size = temp/bas;
	size++;
	size=pow(2,size)-1;
	int tree1[size];
	int tree2[size];
	int tree3[size];
	int j=0;
	for(int i=0;i<size;i++) {
		tree1[i]=0;
		tree2[i]=0;
		tree3[i]=0;
	}
	DFSpre(tree1,pre,n,size,0,&j);
	j=0;
	DFSpost(tree2,post,n,size,0,&j,tree1);
	j=0;
	DFSin(tree3,in,n,size,0,&j,tree1);
	for(int i=0;i<size;i++) cout<<tree1[i]<<" ";
	cout<<endl;
	for(int i=0;i<size;i++) cout<<tree2[i]<<" ";
	cout<<endl;
	for(int i=0;i<size;i++) cout<<tree3[i]<<" ";
	cout<<endl;
}
