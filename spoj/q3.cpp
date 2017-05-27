#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int it=0;it<t;it++){
		string s;
		vector<int> opstack;
		string oupt;
		cin>>s;
		int k=0;
		int i=0;
		while(s.at(i)){
			if(s.at(i)==')'){
				for(int j=i;j!='(';j--){
					if(s.at(j)=='+' || s.at(j)=='-' || s.at(j)=='^' || s.at(j)=='*') opstack.push_back(s.at(j));
					else oupt.at(k++)=s.at(j);
				}
				for(vector<int>::iterator ip=opstack.begin();ip!=opstack.end();ip++){
				oupt.at(k++)=*ip;
				opstack.erase(opstack.begin(),opstack.end());
				}
			}
			i++;
		}
	cout<<oupt;
	}

}
			
							
