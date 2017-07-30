#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		ll sum=0;
		while(n--){
			ll x;
			cin>>x;
			sum |=x;
		}
		cout<<sum<<endl;
	}
}
