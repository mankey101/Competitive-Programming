#include <bits/stdc++.h>
using namespace std;
int maxi(int a,int b){
	if(a>b) return a;
	else return b;
}
int mini(int a,int b){
	if(a>b) return b;
	else return a;
}

int main(){
	int t;
	cin>>t;
	for(int bl=0;bl<t;bl++){
		int n,m;
		cin>>n>>m;
		int a[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
			}
		}
		int max=0;
		int s=m*n;
		int max_ind[s];
		int max_ind1[s];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]>max){
					max=a[i][j];
				}
			}
		}
		int t1=0;
		bool pl[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++) pl[i][j]=false;
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==max){
					max_ind[t1]=i;
					max_ind1[t1]=j;
					t1++;
					pl[i][j]=true;
				}
			}
		}
		int hours=0;
		int flag=1;
		while(1){
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++) if(pl[i][j]==false){flag=0; i=n; j=m;}
			}
			if(flag==1){
				cout<<hours<<endl;	
				break;
			}
			else{
				flag=1;
				for(int it=0;it<t1;it++){
					int k=max_ind[it];
					int l=max_ind1[it];
					for(int i=maxi(0,k-hours-1);i<=mini(k+hours+1,n-1);i++){
						for(int j=maxi(0,l-hours-1);j<=mini(l+hours+1,m-1);j++){
							pl[i][j]=true;
						}
					}
				}
				hours++;	
			}
		}
	}
}


