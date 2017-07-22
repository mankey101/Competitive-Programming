#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count=0;
	int count2=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') count++;
		else if(s[i]=='0') {
			if(count!=0) cout<<count;
			count=0;
			if(s[i-1]=='0') cout<<0;
		}
	}
	if(s[n-1]=='0') cout<<0;
	if(count!=0) cout<<count;
	return 0;
}
