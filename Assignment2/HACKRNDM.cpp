#include <bits/stdc++.h>
using namespace std;
int binser(int *a,int key,int b,int e){
	e--;
	while(b<=e){
		int mid=b + (e-b)/2;
		if(a[mid]==key) return mid;
		else if(a[mid]>key) e=mid-1;
		else b=mid+1;
	}
	return -1;
}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	int count=0;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		int found=binser(a,k+a[i],0,n);
		if(found!=-1) count++;
	}
cout<<count;
} 	
