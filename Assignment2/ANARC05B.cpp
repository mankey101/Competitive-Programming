#include <bits/stdc++.h>
using namespace std;
#define ll	long long
int binser(int *a,int b,int e,int key){
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
	int x=1;
	while(1){
		int n1;
		cin>>n1;
		if(n1==0) return 0;
		int a1[n1];
		ll sum1[n1];
		for(int i=0;i<n1;i++){
			 cin>>a1[i];
			if(i>0) sum1[i]=a1[i]+sum1[i-1];
			else sum1[i]=a1[i];
		}
		int n2;
		cin>>n2;
		int a2[n2];	
		ll sum2[n2];
		for(int i=0;i<n2;i++){
			 cin>>a2[i];
			if(i>0) sum2[i]=a2[i]+sum2[i-1];
			else sum2[i]=a2[i];
		}
		ll sum=0;
		int ind1[n1],ind2[n2];
		int t=0;
		for(int i=0;i<n1;i++){
			int found=binser(a2,0,n2,a1[i]);
			if(found!=-1){ ind1[t]=i; ind2[t++]=found; }
		}
		if(t==0){
			if(sum1[n1-1]<sum2[n2-1]) cout<<sum2[n2-1];
			else cout<<sum1[n1-1]<<endl;
			continue;
		}
		if(sum1[ind1[0]]<sum2[ind2[0]]) sum+=sum2[ind2[0]];
		else sum+=sum1[ind1[0]];
		for(int i=1;i<t;i++){
			if(sum1[ind1[i]]-sum1[ind1[i-1]]<sum2[ind2[i]]-sum2[ind2[i-1]]) sum+=sum2[ind2[i]]-sum2[ind2[i-1]];
			else sum+=sum1[ind1[i]]-sum1[ind1[i-1]];
		}
		if(sum1[n1-1]-sum1[ind1[t-1]]<sum2[n2-1]-sum2[ind2[t-1]]) sum+=sum2[n2-1]-sum2[ind2[t-1]];
		else sum+=sum1[n1-1]-sum1[ind1[t-1]];
	cout<<sum<<endl;
	}
}


