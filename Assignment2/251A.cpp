#include <bits/stdc++.h>
using namespace std;
int binser(int* a,int key, int b,int e){
	e--;
	while(b<e){
		int mid=b +(e-b+1)/2;
		if(a[mid]<=key) b=mid;
		else e=mid-1;
	}
return b;
}
int main(){
	int n,d;
	cin>>n>>d; //lebancho
	int a[n];
	long long count=0;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<=n-3;i++){
		long long temp=0;
		int found=binser(a,a[i]+d,0,n);
		if(found-i>1) temp=(long long)found-(long long)i;
		count=count+ (temp*(temp-1))/2;
	}
cout<<count;
}
