#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	int m,n;
	cin>>m>>n;
	for(int i=m;i<=n;i++){
		int count=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0) {count=1; break;}
			}
		if(count==0 && i!=1) cout<<i<<endl;
		}
	cout<<endl;
	}
}
