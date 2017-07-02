#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b,m;
		cin>>a>>b>>m;
		ll t1=a/m;
		if((double)a/m-t1) t1++;
		ll t2=b/m;
		cout<<t2-t1+1<<endl;
	}
} 
