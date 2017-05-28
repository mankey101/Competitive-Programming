#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int b,m,k;
	cin>>s>>k>>b>>m;
	 int magic[s.length()-k+1];
	magic[0]=0;
	int temp2[k];
	temp2[0]=1;
	for(int i=0;i<k;i++){
		if(i!=0) temp2[i]=temp2[i-1]*(b%m);
		int temp=(s[k-i-1]-48);
		temp2[i]=temp2[i]%m;
		magic[0]=(magic[0]+(temp*temp2[i])%m)%m;
	//	cout<<"agic "<<magic[0]<<endl;
	}
//	cout<<"tem "<<temp2[2]<<endl;
	for(int i=1;i<=s.length()-k;i++){
		int temp=(magic[i-1]-((s[i-1]-48)*temp2[k-1])%m);
		if(temp<0) temp=temp+m;
		magic[i]=(temp*b+s[i+k-1]-48)%m; 
	}
//	for(int i=0;i<s.length()-k+1;i++) cout<<magic[i]<<endl;
	int ans=0;
	for(int i=0;i<=s.length()-k;i++) ans=ans+magic[i];
	cout<<ans;
}	
	
