#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int a;
	for(int it=0;it<t;it++){
		int x,y,p,q;
		cin>>x>>y>>p>>q;
		if(p==q){
			if(x==y) cout<<"0"<<endl;
			else cout<<-1<<endl;
		}
		else if(p==0){
			if(x==0) cout<<"0"<<endl;
			else cout<<"-1"<<endl;
		}
		else{
			int k=x%p;
			
			int j=(p*y-q*x)/(q-p);
			float o=(float)(p*y-q*x)/(q-p);
			if(o>0){
			int temp=j%p;
			j=j+p-temp;
			}
			

			cout<<
			
		}
	}
}
