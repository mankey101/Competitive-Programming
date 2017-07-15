#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,b;
		cin>>n>>b;
		if(n>b){
			if(n>=(2*b)){
				ll mdu=n%b;
				ll k= n/(2*b);
				ll tobe=k*b+mdu;
				cout<<tobe*(n-tobe)/b<<endl;
			}
			else  cout<<n-b<<endl;
		}
		else cout<<0<<endl;
			
	}
}	
