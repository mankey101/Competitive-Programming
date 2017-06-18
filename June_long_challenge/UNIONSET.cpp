#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int ip=0;ip<t;ip++){
		int n,k;
		cin>>n>>k;
		int a[n][k+1];
		for(int i=0;i<n;i++){
			for(int j=0;j<=k;j++) a[i][j]=0;
		}
		for(int j=0;j<n;j++){
			int n1;
			cin>>n1;
			for(int i=0;i<n1;i++){
				int x;
				cin>>x;
				a[j][x]=1;
			}
		}
		int count=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				int flag=0;
				for(int y=1;y<=k;y++){
					if(a[j][y]==0 && a[i][y]==0){ 
						flag=1;
						break;
					}
				}
				if(flag==0) count++;
			}
		}
		cout<<count<<endl;
	}

}
		
