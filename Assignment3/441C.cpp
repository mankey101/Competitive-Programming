#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k;
	cin>>n>>m>>k;
	int i=1,j=1;
	if(k-1>0){
		while(i<=n){
			int flag=0;
			while(j<=m){
				if(k<=1) {flag=1; break;}
				cout<<2<<" "<<i<<" "<<j<<" ";
				if(j==m){
					cout<<i+1<<" "<<j<<endl;
					j--;
					k--;
					break;
				}
				else {
					cout<<i<<" "<<j+1<<endl;
					j+=2;
					if(j>m){ j=m;
					k--;
					break;}
				}
				k--;
			}
			if(flag==1) break;
			i++;
			if(i==n+1) break;
			while(j>=1){
				if(k<=1){ flag=1; break;}
				cout<<2<<" "<<i<<" "<<j<<" ";
				if(j==1){
					cout<<i+1<<" "<<j<<endl;
					k--;
					j++;
					break;
				}
				else {
					cout<<i<<" "<<j-1<<endl;
					j=j-2;
					if(j<1){ j=1;k--; break;}
				}
				k--;
			}
			if(flag==1) break;
			i++;
		}
	}
	//cout<<i<<" "<<j<<endl;
	int len=(i-1)*m;
	if(j!=1 || i!=1) {
		if(i%2==1) len+=j-1;
		else len+=m-j;
	}
		for(int ti=i;ti<=n;ti++){
			if(ti==i){
				cout<<(m*n-len)<<" ";
				if(i%2==1){
					for(int tj=j;tj<=m;tj++){
						cout<<ti<<" "<<tj<<" ";
					}
				}

				else{
					for(int tj=j;tj>=1;tj--){
						cout<<ti<<" "<<tj<<" ";
					}
				}
			}
			
			else{
				if(ti%2==1){
					for(int tj=1;tj<=m;tj++){
						cout<<ti<<" "<<tj<<" ";
					}
				}	
				else{
					for(int tj=m;tj>=1;tj--){
						cout<<ti<<" "<<tj<<" ";
					}
				}
			}
		}
}
	
		
		
