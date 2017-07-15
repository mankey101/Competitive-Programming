#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	long long int sum=0;
	for(int i=0;i<n;i++){
		 cin>>a[i];
		 sum+=a[i];
	}
	if(n==1){
		if(a[0]%2==0) cout<<"0";
		else cout<<"-1";
		return 0;
	}
	if(sum%2==0) cout<<"0";
	else{
		cout<<"1";
	}
}
		
	
