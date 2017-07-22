#include <bits/stdc++.h>
using namespace std;
#define MAX	1000001
bool ai[MAX];
bool bi[MAX];
int main(){
	int n;
	cin>>n;
	int a[n];
	int b[n];
	int maxa,maxb;
	for(int i=0;i<n;i++){
	       	cin>>a[i];
	       	ai[a[i]]=1;
		if(a[i]>maxa) maxa=a[i];
	}
	for(int i=0;i<n;i++) {
		cin>>b[i];
	       	bi[b[i]]=1;
		if(b[i]>maxb) maxb=b[i];
	}
	int am=0,bm=0;
	for(int i=1;i<MAX;i++){
		if(i>min(maxa,maxb)) break;
		int tma=0,tmb=0;
		for(int d=1;d<=MAX/i;d++){
			if(ai[d*i]){
				if(d*i>tma) tma=d*i;
			}
			if(bi[d*i]){
				if(d*i>tmb) tmb=d*i;
			}
		}
		if(tma>0 && tmb>0) {
			am=tma;
			bm=tmb;
		}
	}
	cout<<am+bm;
}
