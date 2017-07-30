#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	ll b,m;
	cin>>m>>b;
	ll max=0;
	for(ll x=0;x<=m*b;x++){
		ll y= x/m;
		if((float)x/(float)m-(x/m)) y++;
		y=b-y;
		if((x+1)*(y+1)*(x+y)>max)  max=(x+1)*(y+1)*(x+y);
	}
	cout<<max/2;
}
