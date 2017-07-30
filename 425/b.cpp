#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	char a[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++) cin>>a[i][j];
	}
	int top=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='B') {
				top=i;
				i=n+1;
				break;
			}
		}
	}
	int bottom=0;
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<m;j++){
			if(a[i][j]=='B') {
				bottom=i;
				i=-1;
				break;
			}
		}
	}
	int left=0;
	for(int j=0;j<m;j++){
		for(int i=0;i<m;i++){
			if(a[i][j]=='B') {
				left=j;
				j=m+1;
				break;
			}
		}
	}
	int right=0;
	for(int j=m-1;j>=0;j--){
		for(int i=0;i<n;i++){
			if(a[i][j]=='B') {
				right=j;
				j=-1;
				break;
			}
		}
	}
	int count=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='B') count++;
		}
	}
	int rangeup=bottom-top+1;
	int rangewid=right-left+1;
	int range=max(rangeup,rangewid);
	if(range*range > (m*n) ) {cout<<-1; return 0;}
	cout<<range*range-count;
}

