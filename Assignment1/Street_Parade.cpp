#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	while(n!=0){
		int a[n];
		vector<int> mobiles;
		for(int i=0;i<n;i++) cin>>a[i];
		int count=1;
		for(int i=0;i<n;i++){
			if(a[i]!=count){
				if(!mobiles.empty()){
					while(mobiles.back()==count){
						mobiles.pop_back();
						count++;
					}
				}	
				if(mobiles.empty() || (!mobiles.empty() && mobiles.back()>a[i])) mobiles.push_back(a[i]);
				else{
					break;
				}
			}
			else count++;		
		}
		while(mobiles.back()==count){
			mobiles.pop_back();
			count++;
		}
		if(count==n+1) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	cin>>n;
	}
	
}	
