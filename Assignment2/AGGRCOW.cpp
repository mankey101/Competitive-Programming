#include <bits/stdc++.h>
using namespace std;
#define ll	long long
ll next(ll* a,ll n, ll key){
	ll b=0;
	ll e=n;
	while(b<e){
		ll mid=b+ (e-b)/2;
		if(a[mid]<key) b=mid+1;
		else e=mid;
	}
	return b;
}	
bool f(ll* a , ll n, ll c, ll per){
	ll i;
	ll j=0;
	c--;
	while(1){
		i=next(a,n,per+a[j]);
		if((i==n-1 && a[i]-a[j]<per) ||i>=n ) break;
		c--;
		j=i;
		if(c<=0) return false;
	}
	 return true;
}
int main(){
	int t;
	cin>>t;
	for(ll lp=0;lp<t;lp++){
		ll n,c;
		cin>>n>>c;
		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		ll b=0,e=(1e10);
		while(b<e){
			ll mid=b + (e-b+1)/2;
			if(f(a,n,c,mid)==false) b=mid;
			else e=mid-1;
		}
	cout<<b<<endl;	
	}
}
	
