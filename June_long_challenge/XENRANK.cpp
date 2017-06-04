#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		long long int u,v;
		cin>>u>>v;
		long long int rank;
		long long int big=(u+v)*(u+v);
		long long int small= u+v;
		rank=(big+small)/2;
		long long int hj=u+1;
		rank+=hj;
		cout<<rank<<endl;
	}
}
