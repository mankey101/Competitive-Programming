#include <bits/stdc++.h>
using namespace std;
#define ll	long long

int main(){
	ll n,k;
	cin>>n>>k;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	ll init=k*2;
	long double x=(long double)a[n-1]/init;
	long double y=log(x)/log(2.0);
	ll ans=(ll) y;
	cout<<ans+1;
}



