#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cin>>a[i][j];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]!=1){
				int flag=0;
				for(int k=0;k<n;k++){
					for(int l=0;l<n;l++){
						if(a[i][k]+a[l][j]==a[i][j]) flag=1;
					}
				}
				if(flag==0) {cout<<"No"; return 0;}
			}
		}
	}
	cout<<"Yes";
	return 0;
}
