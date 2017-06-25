#include <bits/stdc++.h>
using namespace std;
#define ll	unsigned long long
int main(){
	ll a,b;
	cin>>a>>b;
	ll T=1;
	ll i=1;
	while((T%a)!=0){
		i++;
		T=T*i;
		T=T%a;
	}
	ll j=1;
	T=1;
	while((T%b)!=0){
		j++;
		T=T*j;
		T=T%b;
	}
	if(i<j) cout<<j-i;
	else cout<<0;
}
		
	
			
