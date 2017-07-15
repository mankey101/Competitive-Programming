#include <bits/stdc++.h>
using namespace std;
#define ll	long long
#define maxi	100000000
char s[maxi];
int main(){
	ll n;
	cin>>n;
	ll max=0;
	for(ll i=0;i<n;i++){
		string t;
		cin>>t;
		ll len=t.length();
		ll qu;
		cin>>qu;
		for(ll j=0;j<qu;j++){
			ll start;
			cin>>start;
			start--;
			for(ll k=0;k<len;k++){
				s[start++]=t[k];
			}
			if(start>max) max=start;
		}
	}
	for(int i=0;i<max;i++){
		if(s[i]==0) s[i]='a';
	}
	cout<<s;
}
