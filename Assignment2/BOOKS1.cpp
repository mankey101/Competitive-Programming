#include <bits/stdc++.h>
using namespace std;
#define ll	long long
bool g(ll* p, ll per, ll m,ll k){
	ll count=0;
	ll temp=0;
	for(ll i=0;i<m;i++){
		temp+=p[i];
		if(temp>per){
			i--;
			 count++;
			temp=0;
		}
	}
	if(count+1<=k) return true;
	else return false;
}
	

 
int main(){
	int n;	
	cin>>n;
	for(int yu=0;yu<n;yu++){
		int m,k;
		cin>>m>>k;
		ll p[m];
		ll max=0;
		for(int i=0;i<m;i++){
			 cin>>p[i];
			if(p[i]>max) max=p[i];
		}
		ll b=max;
		ll e=(1e12);
		while(b<e){
			ll mid=b + (e-b)/2;
			if(g(p,mid,m,k)==true) e=mid;
			else b=mid+1;
		}
	ll count=0;
	ll temp=0;
	char sp[m-1];
	for(int i=0;i<m-1;i++) sp[i]=0;
		for(int i=0;i<m;i++){
			temp+=p[i];
			if(temp>b) {
				temp=0;
				count++;
				sp[i-1]='/';
				i--;
			}
		}
	for(ll i=0;i<k-count-1;i++){
		if(sp[i]!='/') sp[i]='/';
	}
	for(int i=0;i<m;i++){
		cout<<p[i]<<" ";
		if(i!=m-1) {if(sp[i]=='/') cout<<sp[i]<<" ";}
	}
	cout<<endl;
	}
}
