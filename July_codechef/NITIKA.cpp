#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string name;
		getline(cin,name);
		int count=0;
		string s1[3];
		string output;
		int j=0;
		for(int i=0;i<name.length();i++){
			if(name[i]==' ') {
				count++;
				continue;
			}
			 s1[count]+=name[i];
		}
		if(count!=0){
			if(s1[0][0]>'Z') s1[0][0]-=32;
		       output+=s1[0][0];
		       output+=". ";
		}
 		if(count==2){
			if(s1[1][0]>'Z') s1[1][0]-=32;
			output+=s1[1][0];
			output+=". ";
		}
		for(int i=0;i<s1[count].length();i++){
			if(i==0) {
				if(s1[count][i]>'Z') s1[count][i]-=32;
				output+=s1[count][i];
				continue;
			}	
			if(s1[count][i]<'a') s1[count][i]+=32;
			output+=s1[count][i];
		}
		cout<<output<<endl;

	}	
}	
