#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a,a+n);
		long long sumt=0;
		int j=n-1;
		while(a[j]>=0 && j>=0){
			sumt=sumt+a[j];
			j--;
		}
		long long sumn=0;
		int it=j;
		int pel=n-j-1;
		int count=0;
		for(it=j;it>=0;it--){
			if(sumt*pel+a[it] < (sumt+a[it])*(pel+1)){
				sumt=sumt+a[it];
				pel++;
			}
			else break;
		}
		sumn=sumt*pel;
		for(int ip=it;ip>=0;ip--) sumn+=a[ip];
	cout<<sumn<<endl;
	}

}
	
	
