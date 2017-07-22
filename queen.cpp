#include <bits/stdc++.h>
using namespace std;
int n;
bool board[100][100];
bool isCheck(int col,int row){
	for(int j=0;j<col;j++){
		for(int i=0;i<n;i++){
			if(board[i][j]){
			       if(i==row) return true;
		       		if((col==j-i+row) ||( col==i+j-row)) return true;
			}
		}
	}
	return false;	
}



bool DFS(int col){

	for(int i=0;i<n;i++){
		if(!isCheck(col,i)){
			board[i][col]=true;
			if(col==n-1) return true;
			bool l=DFS(col+1);
			if(l==false) board[i][col]=false;
			else return true;
		}
	}

	return false;
}


int main(){
	cin>>n;
	DFS(0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<board[i][j]<<" ";
		cout<<endl;
	}
}
