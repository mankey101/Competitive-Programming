#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int pi[n];
	int temp[n];
	for(int i=0;i<n;i++){
		 cin>>pi[i];
		temp[i]=pi[i];
	}
	for(int i=0;i<m;i++){
		int l,r,x;
		cin>>l>>r>>x;
		if(x<l || x>r) cout<<"Yes"<<endl;
		else {
			int temp2[n];
			for(int i=l-1;i<r;i++) temp2[i]=temp[i];
			sort(temp2+l-1,temp2+r);
			if(temp2[x-1]==pi[x-1]) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
}
				
