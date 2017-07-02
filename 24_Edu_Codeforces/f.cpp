#include <bits/stdc++.h>
using namespace std;
#define ll	long long
ll binser(ll *a,ll b,ll e,ll key){
	e--;
	ll n=e;
	while(b<e){
		ll mid=b+(e-b)/2;
		if(a[mid]>key) e=mid;
		else b=mid+1;
	}
	if(b==n && a[b]<=key) return -1;
	return b;
}
int main(){
	ios_base::sync_with_stdio(false);
	ll t;
	cin>>t;
	while(t--){
		ll n,s;
		cin>>n>>s;
		ll a[n];
		for(ll i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		ll sum[n];
		sum[0]=a[0];
		for(ll i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
		ll k=-1;
		bool flag=1;
		ll b=0,e=a[n-1];
		while(b<e){
			ll mid=b+(e-b)/2;
			ll ind=binser(a,0,n,mid);
		//	cout<<b<<" "<<e<<endl;
			if(ind==-1) ind=n;
			ll lhs;
			if(ind!=0) lhs=sum[ind-1];
			else lhs=0;
			ll rhs= mid*(n-ind);
			if(lhs+rhs==s){cout<<mid<<endl; flag=0; break;}
			else if(lhs+rhs>s) e=mid-1;
			else b=mid+1;
		}
		if(flag==1){
			ll mid=b;
			ll ind=binser(a,0,n,mid);
                        if(ind==-1) ind=n;
                        ll lhs;
                        if(ind!=0) lhs=sum[ind-1];
                        else lhs=0;
                        ll rhs= (ll)mid*(ll)(n-ind);
                        if(lhs+rhs==s) cout<<mid<<endl;	
			else cout<<-1<<endl;
		}
	}
}			
		
			
	
	
