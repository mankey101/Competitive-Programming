#include <iostream>
using namespace std;
#define ll	long long
int main(){
	int t;
	cin>>t;
	while(t--){
		ll k;
		cin>>k;
		k--;
		//cout<<k<<endl;
		if(k%4==3) {
			ll temp=(k+1)/4;
			while(temp%2==0) temp=temp/2;
			temp=temp%4;
			if(temp==1) cout<<'a'<<endl;
			if(temp==3) cout<<'c'<<endl;
		}
		if(k%8==0) cout<<'a'<<endl;
		if(k%8==1) cout<<'a'<<endl;
		if(k%8==2) cout<<'c'<<endl;
		if(k%8==4) cout<<'a'<<endl;
		if(k%8==5) cout<<'c'<<endl;
		if(k%8==6) cout<<'c'<<endl;
	}
}
	
