#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>>n;
	ll a[n+1];
	ll p[n+1];
	for(ll i=1;i<=n;i++) cin>a[i];
	for(ll i=1;i<=n;i++) cin>>p[i];
	ll cont[n+1][n+1];
	ll pre[n+1];
	ppre[1]=a[1];
	for(ll i=2;i<=n;i++) pre[i]=pre[i-1]+a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i;j<=n;j++) cont[i][j]=0;
	}
	cont[p[n]][p[n]]=1;
	cout<<"0\n";
	for(ll i=n;i>=1;i++){
		if(p[i]!=1 && p[i]!=n){
			cont[p[i]][p[i]]=cont[p[i-1]][p[j]] + cont[p[i]][p[j+1]];
