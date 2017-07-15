#include <bits/stdc++.h>
using namespace std;
#define ll	long long
struct ticket{
	ll diff;
	ll l;
	ll r;
	ll cost;
};
bool acompare(ticket lhs, ticket rhs) {
	if(lhs.diff==rhs.diff) return lhs.l< rhs.l;
	 return lhs.diff < rhs.diff;
 }
bool costt(ticket lhs, ticket rhs) {
        if(lhs.diff==rhs.diff) return lhs.cost< rhs.cost;
         return lhs.diff < rhs.diff;
 }
int main(){
	ll n,x;
	cin>>n>>x;
	ticket mine[n],copy[n];
	for(ll i=0;i<n;i++){
		ll a,b,c;
		cin>>a>>b>>c;
		mine[i].diff=b-a+1;
		copy[i].diff=b-a+1;
		mine[i].l=a;
		copy[i].l=a;
		mine[i].r=b;
		copy[i].r=b;
		mine[i].cost=c;
		copy[i].cost=c;
	}
	sort(mine,mine+n,acompare);
	sort(copy,copy+n,costt);
	ll minco=1000000000000;
	for(ll i=0;i<n;i++){
		ll midd=x/2;
		if(mine[i].diff<=midd){
			ll start=-1,end=-1;
			ll b=0,e=n-1;
			while(b<e){
				ll mid=b+(e-b)/2;
				if(mine[mid].diff+mine[i].diff==x) e=mid;	
				else if(mine[mid].diff<x-mine[i].diff) b=mid+1;
				else if(mine[mid].diff>x-mine[i].diff) e=mid-1;
			}
			if(mine[b].diff+mine[i].diff==x) start=b;
			 b=0,e=n-1;
			while(b<e){
				ll mid=b+(e-b+1)/2;
				if(mine[mid].diff+mine[i].diff==x) b=mid;
				else if(mine[mid].diff<x-mine[i].diff) b=mid+1;
				else if(mine[mid].diff>x-mine[i].diff) e=mid-1;
			}
			if(mine[b].diff+mine[i].diff==x) end=b;
			if(mine[end].r<mine[i].l){
				if(copy[start].l==mine[i].l) start++;
				ll temp=mine[i].cost+copy[start].cost;
				if(temp<minco) minco=temp;
			} 
			else{	
				for(ll c=end;c>=start;c--){
					if(mine[c].l>mine[i].r){
							ll temp=mine[i].cost+mine[c].cost;
							if(temp<minco) minco=temp;
					}
					else break;
				}
			}
		}
	}

	if(minco==1000000000000) cout<<-1;
	else cout<<minco;
}
