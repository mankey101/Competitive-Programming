#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll a,b,n;
		cin>>a>>b>>n;
		if(n%2==0){
			cout<<max(a,b)/min(a,b)<<endl;
			continue;
		}
		if(b>2*a) {
			cout<<b/(a*2)<<endl;
		}
		else{
			cout<<(a*2)/b<<endl;
			continue;
		}
	}
}
