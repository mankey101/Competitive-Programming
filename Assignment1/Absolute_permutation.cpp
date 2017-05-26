#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int it=0;it<t;it++){
		int n,k;
		cin>>n>>k;
		if(k==0) {
			for(int i=1;i<=n;i++) cout<<i<<" ";
			cout<<endl;
		}
		else{
		if(n%(2*k)==0){
			int t=k*2;
			int temp=0;
			for(int i=1;i<=n;i++){
				if(i<=temp*t+k){
					cout<<k+i<<" ";
				}
				else cout<<i-k<<" ";
				if(i==t*(temp+1) ) temp++;
			}
			cout<<endl;
		}
		else cout<<"-1"<<endl;
		}
	}
}
		
