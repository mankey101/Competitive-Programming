#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int out[n];
		for(int i=0;i<n;i++){
			out[i]=500-i;
		}
		for(int i=0;i<n;i++) cout<<out[i]<<endl;
	}
}
