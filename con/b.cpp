#include <bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2;
	cin>>n1>>n2;
	char a[n1],b[n2];
	cin>>a>>b;
	int tbp;
	int min=n1;
	for(int i=0;i<=n2-n1;i++){
		int count=0;
		int j;
		for(j=0;j<n1;j++){
			if(b[i+j]!=a[j]) count++;
		}
		if(count<=min){
			 min=count;
			tbp=i;
		}
	}
	cout<<min<<endl;
	int x=-1;
//	cout<<b[tbp]<<endl;
	for(int t=tbp;t<tbp+n1;t++){
		x++;
		if(b[t]!=a[x]) cout<<x+1<<" ";
	}
}
	
