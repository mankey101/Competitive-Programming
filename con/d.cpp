#include <bits/stdc++.h>
using namespace std;
bool f(int len,char *a,int n,int k){
	int cnta=0,cntb=0;
	for(int i=0;i<len;i++) {
		if(a[i]=='a') cnta++;
		else cntb++;
	}
	if(min(cnta,cntb)<=k) return true;
	for(int i=len;i<n;i++){
		if(a[i]=='a' && a[i-len]=='b') {
			cnta++;
			cntb--;
		}
		else if(a[i]=='b' && a[i-len]=='a'){
			cntb++;
			cnta--;
		}
		if(min(cnta,cntb)<=k) return true;
	}
	return false;
} 	

int main(){
	int n,k;
	cin>>n>>k;
	char a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int b=1, e=n;
	while(b<e){
		int mid=b+ (e-b+1)/2;
		if(f(mid,a,n,k)) b=mid;
		else e=mid-1;
	}
	if(f(b,a,n,k)) cout<<b;
	else cout<<0;
}
