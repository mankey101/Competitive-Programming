#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	ll n,k;
	cin>>n>>k;
	ll mid=n/2;
	ll y= n/(2*(k+1));
	ll x;
	 x=k*y;
	cout<<y<<" "<<x<<" "<<n-x-y;
}
