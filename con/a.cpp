#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	ll a,b;
	cin>>a>>b;
	ll c=min(a,b);
	ll d=1;
	for(ll i=c;i>=1;i--){
		d=d*i;
	}
	cout<<d;
}
