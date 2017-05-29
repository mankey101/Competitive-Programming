#include <bits/stdc++.h>
using namespace std;
#define ll	 long long 
ll min(ll a,ll b){
	if(a>b) return b;
	else return a;
}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		ll n;
		cin>>n;
		ll h[n];
		if(n==1){
			cin>>h[0];
			cout<<h[0]-1;
			return 0;
		}
		for(ll j=0;j<n;j++) cin>>h[j];
		ll left[n];
		left[0]=min(h[0],1);
		for(ll j=1;j<n;j++){
			left[j]=min(left[j-1]+1,h[j]);
		}
		ll right[n];
		right[n-1]=min(h[n-1],1);
			for(ll j=n-2;j>=0;j--){
			right[j]=min(right[j+1]+1,h[j]);
			}	
		ll max=min(left[0],right[0]);
		ll max_index=0;
		for(ll j=1;j<n;j++){
			if(min(left[j],right[j])>max){
				 max_index=j;	
				max=min(left[j],right[j]);
			}		
		}
		ll sum=0;
		ll lefti=max_index-max+1;
		ll righti=max_index+max-1;
		for(ll j=0;j<lefti;j++) sum+=h[j];
		for(ll j=righti+1;j<n;j++) sum+=h[j];
		ll k=1;
		bool flag=0;
		for(ll j=lefti;j<=righti;j++){
			sum+=h[j]-k;
			if(k==max) flag=1;
			if(flag==0) k++;
			else if(flag) k--;
		}
	cout<<sum<<endl;			
	}
}
