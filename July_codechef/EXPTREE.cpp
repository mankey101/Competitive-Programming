#include <bits/stdc++.h>
using namespace std;
#define ll	long long

// C function for extended Euclidean Algorithm
ll modInverse(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}
int main(){
	ll N1=1e9+7;
	ll N2=1e9+9;
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		if(n==1) {cout<<0<<" "<<0<<endl; continue;}
		ll p1=((n%N1)*((n-1)%N1))/2;
		ll q1=(n*2-3)%N1;
		ll p2=((n%(N2))*((n-1)%N2))/2;
		ll q2=(n*2-3)%N2;
		ll inv1=modInverse(q1,N1);
		ll inv2=modInverse(q2,N2);
		ll ans1=((p1%N1)*(inv1%N1))%N1;
		ll ans2=((p2%N2)*(inv2%N2))%N2;
		cout<<ans1<<" "<<ans2<<endl;
	}
}

