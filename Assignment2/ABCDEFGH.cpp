#include <bits/stdc++.h>
using namespace std;
#define ll	long long
ll binserl(ll *a,ll b,ll e,ll key){
	e--;
	while(b<e){
		ll mid=b+ (e-b+1)/2;
		if(a[mid]<=key) b=mid;
		else e=mid-1;
	}
	if(a[b]!=key) return -1;
	else return b;
}
ll binseru(ll *a,ll b,ll e,ll key){
	e--;
	while(b<e){
		ll mid= b+ (e-b)/2;
		if(a[mid]>=key) e=mid;
		else b=mid+1;
	}
	if(a[b]!=key) return -1;
	else return b;
}
int main(){
	ll n;
	cin>>n;
	ll ar[n];
	for(ll i=0;i<n;i++) cin>>ar[i];
	ll t=n*n*n;
	ll a[t];
	ll it=0;
	for(ll i=0;i<n;i++){
		for(ll j=0;j<n;j++){
			for(ll k=0;k<n;k++){
				a[it]=ar[i]*ar[j] + ar[k];
				it++;
			}
		}
	}
	ll b[t];
	it=0;
	for(ll i=0;i<n;i++){
		if(ar[i]==0) continue;
		for(ll j=0;j<n;j++){
			for(ll k=0;k<n;k++){
				b[it]=(ar[k]+ar[j])*ar[i];
				it++;
			}
		}
	}
	sort(a,a+t);
	sort(b,b+it);
	ll count=0;
//	for(int i=0;i<it;i++) cout<<a[i]<<" "<<b[i]<<endl;
	for(ll i=0;i<t;i++){
		ll found=binserl(b,0,it,a[i]);
		ll foundu=binseru(b,0,it,a[i]);
//		cout<<found<<" "<<foundu<<endl;
		if(found!=-1) count+=found-foundu+1;
	}
cout<<count;
}
		
