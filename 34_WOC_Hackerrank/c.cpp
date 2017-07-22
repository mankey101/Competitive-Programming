#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int main(){
	int n,q;
	cin>>n>>q;
	ll a[n];
	for(int i=0;i<n;i++){
	       	cin>>a[i];
	}
	map<ll,vector<ll> > m;
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			m[a[i]].push_back(i);
			for(int j=i;j<n;j++){
				if(a[j]==a[i]) {
					m[a[i]].push_back(j);
					a[j]=0;
				}
			}
		}
	}

}


	


