#include <bits/stdc++.h>
using namespace std;
int main(){
	int q;
	cin>>q;
	map<string,int> m;
	for(int it=0;it<q;it++){
		int index;
		string name;
		int marks;
		cin>>index>>name;
		if(index==1) cin>>marks;
		if(index==1){
			if(m.find(name)==m.end())  m.insert(make_pair(name,marks));
			else{
				m[name]+=marks;
			}
		}
		else if(index==2){
			m[name]=0;
		}
		else{
		cout<<m[name]<<endl;				
		}	
	}
}
