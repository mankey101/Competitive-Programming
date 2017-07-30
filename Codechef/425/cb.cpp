#include <bits/stdc++.h>
using namespace std;
void solve(bool *g,string inp){
	string s;
	cin>>s;
	int i,ipp;
	if(inp.length()>s.length()+1){cout<<"NO"<<endl; return ;}
	if(inp.length()==s.length()+1){
		int j=-1;
		for(int i=0;i<inp.length();i++){
			if(inp[i]=='*') continue;
			j++;
			if(inp[i]==s[j] || (inp[i]=='?' && g[s[j]-'a'])){ continue;}
			else {cout<<"NO"<<endl; return ;}
		}
		cout<<"YES"<<endl;
		return ;
	}

	for(i=0;inp[i]!='*';i++){
		if(inp[i]=='?') {
			if(!g[s[i]-'a']){cout<<"NO"<<endl; return ;}
		}
		else if(s[i]!=inp[i]) {cout<<"NO"<<endl; return;}
	}
	int j=inp.length()-1;
	int k=s.length()-1;
	while(inp[j]!='*'){
		if(inp[j]=='?') {
			if(!g[s[k]-'a']){cout<<"NO"<<endl; return ;}
		}
		else if(inp[j]!='?' && inp[j]!=s[k]) {cout<<"NO"<<endl; return ;}
		j--; k--;
	}
	for(int l=i;l<=k;l++){
		if(g[s[l]-'a']) {cout<<"NO"<<endl; return ;}
	}
	cout<<"YES"<<endl;
	return ;
}


int main(){
	string s;
	cin>>s;
	bool g[26];
	for(int i=0;i<26;i++) g[i]=false;
	for(int i=0;i<s.length();i++){
		g[s[i]-'a']=true;
	}
	string inp;
	cin>>inp;
	bool flag=0;
	for(int i=0;i<inp.length();i++){
		if(inp[i]=='*') {
			flag=true;
			break;
		}
	}
	if(!flag){
		int q;
		cin>>q;
		while(q--){
			string f;
			cin>>f;
			if(f.length()!=inp.length()){
				cout<<"NO"<<endl;
				continue;
			}
			bool flag=0;
			for(int i=0;i<inp.length();i++){
				if(inp[i]==f[i] || (inp[i]=='?' && g[f[i]-'a'])) continue;
				else {cout<<"NO"<<endl; flag=1; break;}
			}
			if(flag==0) cout<<"YES"<<endl;
		}
	}
	else{
		int q;
		cin>>q;
		while(q--){
			solve(g,inp);
		}
	}
}




								
			
		
