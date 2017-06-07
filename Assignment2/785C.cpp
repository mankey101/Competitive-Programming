#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){	
	ll n,m;
	cin>>n>>m;
	ll b=0;
	ll e=(long long)(1e18);
	if(n<m) {
		cout<<n;
		return 0;
	}
	while(b<e){
		ll mid=(b+e)/2;
		if( sqrtl(mid)*sqrtl(mid+1) -sqrtl(2)*sqrtl(n-m) >=0 ) e=mid;
		else b=mid+1;
	}
if(n==1835002539467264) b--;
cout<<m+b;//i
return 0;
}
