#include <bits/stdc++.h>
using namespace std;
#define ll	long long
bool f(ll n,ll s){
	ll temp=n;
	ll sum=0;
	while(temp!=0){
		sum+=temp%10;
		temp/=10;
	}
	if(n-sum>=s) return true;
	else return false;
}
int main(){
	ll n,s;
	cin>>n>>s;
	ll b=1;
	ll e=n;
	ll count=0;
	while(b<e){
		ll mid=b+ (e-b)/2;
		if(f(mid,s)) e=mid;
		else b=mid+1;
	}
	if(!f(b,s)) cout<<"0";
	else  cout<<n-b+1;
}
	
