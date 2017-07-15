#include <bits/stdc++.h>
using namespace std;
int a[10000000];
bool visited[10000000];
int main(){
	int n,k;
	cin>>n>>k;
	int in[n];
	int b[k];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(i!=0) in[i]=in[i-1]+x;
		else in[i]=x;
	}
	int min=0;
	for(int i=0;i<n;i++) {
		if(in[i]<min) min=in[i];
	}
	if(min<0){
		for(int i=0;i<n;i++) in[i]-=min;
	}
	for(int i=0;i<n;i++){
		a[in[i]]=1;
	}	
	int count=0;
	for(int i=0;i<k;i++) cin>>b[i];
	for(int i=0;i<n;i++){
		if(!visited[in[i]]){
		       	visited[in[i]]=1;
			bool flag=1;
			for(int j=1;j<k;j++){
				int t;
				t=b[j]-(b[0]-in[i]);
				if(t>=0){
				       if(!a[t]){ flag=0; break;}
				}
			}
			if(flag==1) count++;
		}
	}
	cout<<count<<endl;
}
			

		


	
