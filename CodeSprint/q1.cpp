#include <iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int l=0,r=0;
	for(int i=0;i<n/2;i++){
		l=l+a[i];
		r=r+a[n-i-1];
	}
	int diff;
	diff=r-l;
	if(diff<0) diff=-diff;
	 cout<<diff;
}
