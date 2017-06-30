#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int l[m];
	for(int i=0;i<m;i++) cin>>l[i];
	int a[n+1];
	for(int i=0;i<=n;i++) a[i]=0;
	for(int i=0;i<m-1;i++){
	//	for(int i=1;i<=n;i++) cout<<a[l[i]]<<" ";
	//	cout<<endl;
		if(l[i+1]<=l[i]){
			if(!a[l[i]]){ a[l[i]]=l[i+1]-l[i]+n;}
			else {
				if(a[l[i]]!=l[i+1]-l[i]+n) { cout<<-1; return 0;}
			}
		}
		else{
			if(!a[l[i]]) a[l[i]]=l[i+1]-l[i];
			else {
				if(a[l[i]]!=l[i+1]-l[i]) { cout<<-1; return 0;}
			}
		}
	}
	//for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	bool b[n+1];
	for(int i=0;i<=n;i++) b[i]=0;
	for(int i=1;i<=n;i++) {
		if(a[i]!=0){
			if(!b[a[i]]) b[a[i]]=1;
			else {cout<<-1; return 0;}
		}
	}
	//for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	for(int i=1;i<=n;i++){
		int flag=0;
		if(a[i]==0) {
			for(int j=1;j<=n;j++) {if(!b[j]) {flag=1; b[j]=1; a[i]=j; break;}}
			if(flag==0) {cout<<-1; return 0;}
		}
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
}
		
