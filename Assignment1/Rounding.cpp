#include <iostream>
#include <string>
using namespace std;
int main(){
	string s;
	int k;
	cin>>s;
	cin>>k;
	int count=k;
//	for(int i=0;i<s.length();i++) cout<<s[i];
	int k1=0;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]!='0'){ k1++;  s[i]='}';}
		else if(s[i]=='0' && count!=1)  count--;
		else if(s[i]=='0' && count==1){
		cout<<k1;
		return 0;
		}
	}
	if(s[0]=='}'){ cout<<s.length()-1; return 0;}
	else if(s[0]=='0')  cout<<"0"; 
}
	
