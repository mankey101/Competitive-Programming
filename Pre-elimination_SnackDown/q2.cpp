#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		int a[m],b[m];
		for(int j=0;j<m;j++){
			cin>>a[j]>>b[j];
		}
		if(n%2==0) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
