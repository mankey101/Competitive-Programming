#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n],b[n],c[n],d[n];
	for(int i=0;i<n;i++){
		 cin>>a[i];
		c[i]=a[i];
	}
	for(int i=0;i<n;i++){
		 cin>>b[i];
		d[i]=b[i];
	}
	sort(a,a+n);
	sort(b,b+n);
	int i1,i2;
	for(i1=0;i1<n;i1++) if(c[i1]==a[0]) break;
	for( i2=0;i2<n;i2++) if(d[i2]==b[0]) break;
	if(i1!=i2){
		cout<<a[0]+b[0];
	}
	else{
		if(a[0]+b[1]>a[1]+b[0]) cout<<a[1]+b[0];
		else cout<<a[0]+b[1];
	}
}
