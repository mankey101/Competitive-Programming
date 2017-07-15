#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int maxl=0,maxr=0;
		bool flag=0;
		int count=0;
		bool flag2=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='<'){
				if(flag2==0){
					flag=0;
					flag2=1;
					count++;
					maxl=1;
					continue;
				}
				if(flag==0) {
					count++;
					if(count>maxl) maxl=count;
				}
				if(flag==1){
					count=1;
					if(maxl<count) maxl=count; 
					flag=0;
				}
			}
			else if(s[i]=='>'){
				if(flag2==0){
					flag=1;
					flag2=1;
					count++;
					maxr=1;
					continue;
				}
				if(flag==1){
					count++;
					if(count>maxr) maxr=count;
				}
				else {
					count=1; 
					if(count>maxr) maxr=count;
					flag=1;
				}
			}
		//	cout<<flag<<" "<<maxl<<" "<<maxr<<endl;
		}
		//if(flag2==0) cout<<1<<endl;
		 cout<<max(maxl,maxr)+1<<endl;
	}

}

