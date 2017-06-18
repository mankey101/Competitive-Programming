#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		string s;
		cin>>s;
		int count=0;
		for(int j=0;j<s.length();j++){
			if(s[j]=='1'){
				int k;
				for( k=j+1;k<s.length();k++){
					if(s[k]=='0') continue;
					else break;
				}
				if(s[k]=='1') count++;
			j=k-1;
			}
		}
		cout<<count<<endl;
	}
return 0;
}
			
