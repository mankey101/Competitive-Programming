#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		char up[n];
		char di[n];
		cin>>up>>di;
		int u=0,v=0;
		while(u<n && up[u]=='.') u++;
		while(v<n && di[v]=='.') v++;
		int stat;
		if(u==v){
//			cout<<"hi";
			while(u<n && v<n && up[u]==di[v] && up[u]=='#'){ u++; v++;}
			while(u<n && v<n && up[u]==di[v] && up[u]=='.'){ u++; v++;}
			if(u==n) {cout<<"yes"<<endl; continue;}
			if(up[u]=='#'){
				stat=1;
				if(u>0 && up[u-1]=='.') {cout<<"no"<<endl; continue;}
			}
			else if(di[u]=='#'){
				stat=0;
				if(u>0 && di[u-1]=='.') {cout<<"no"<<endl; continue;}
			}
			else {cout<<"no"<<endl; continue;}
		}
//			cout<<u<<v<<endl;
			int down=0,upp=0;
			if(u<v){ stat=1; v=u;}
			else{ stat=0; u=v;}
			while(u<n-1 && v<n-1){
			//	cout<<"u is "<<u<<" "<<v<<endl;
				if(up[u+1]=='.' && di[u+1]=='.'){
						// cout<<"hi";
						int k;
						for(k=u+1;k<n;k++){
						if(up[k]!='.' || di[k]!='.'){cout<<"no"; break;}
					}
					if(k==n) {cout<<"yes"; break;}
					else break;
				}
				if(stat==1){
					if(upp==1) {u++; v++; if(up[u]=='.') {cout<<"no"; break;}}
					if(di[u]=='#'){
						stat=0;
						down=1;
					}
					else{
						if(up[u+1]=='#'){ u++; v++;}
						else {cout<<"no"; break;}
					}
				}
				else{
					if(down==1){ v++; u++; if(di[v]=='.'){cout<<"no"; break;} }
					if(up[v]=='#') {
						stat=1;
						upp=1;	
					}
					else{
						if(di[v+1]=='#') {u++; v++;}
						else{
							if(di[v+1]=='#'){u++; v++; down=0;}
							else {cout<<"no"; break;}
						}
					}
				}
			}
			if(u==n-1){ cout<<"yes"; continue;}
	cout<<endl;						
				

	}
}
