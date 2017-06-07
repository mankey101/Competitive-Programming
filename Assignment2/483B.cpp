#include <bits/stdc++.h>
using namespace std;
bool finde(long long mid,long long p1,long long p2,long long c1,long long c2){
	long long f[]={mid/p1,mid/p2};
	long long lc=p1*p2;
	long long com=mid/lc;
	long long bache=mid-f[0]-f[1]+com;
  f[0]=f[0]-com;
	f[1]=f[1]-com;
	long long ct1=c1-f[1];
	long long ct2=c2-f[0];
	if(ct1<0) ct1=0;
	if(ct2<0) ct2=0;
	return (ct1+ct2<=bache);
}

int main(){
	long long v=0;
	long long c1,c2,p1,p2;
	cin>>c1>>c2>>p1>>p2;
	long long b=1;
	long long e=(long long) (1e18);
	while(b<e){
		long long mid=b + (e-b)/2;
		if(finde(mid,p1,p2,c1,c2)) e=mid;
		else b=mid+1;
	}
	cout<<b;
}
