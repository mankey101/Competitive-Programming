#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	int a;
	for(int it=0;it<t;it++){
		long long int x,y,p,q;
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
			if(p*y-q*x>0){
				long long int k;
				long long int num=p*y-q*x;
				long long int den=q-p;
				long long int nfrac=num/den;
				double frac=(float)num/den;
				long long int alfa;
				if(frac-nfrac) alfa=nfrac+1;
				else alfa=nfrac;
//				cout<<alfa<<endl;
				long long int temp=x%p;
				long long int temp2=alfa%p;
				if(temp==0){if(temp2!=0)  alfa=alfa+p-temp2;}
				else{
					if(p-temp<temp2) alfa=alfa+p-temp-temp2+p;
					else alfa=alfa+p-temp-temp2;
				}
			//	cout<<alfa<<endl;
				cout<<(alfa+x)/p*q-y;
			}
			else if(p*y<q*x){
				long long int k=x%p;
				long long int j=0;
				if(k!=0)  j=p-k;
//				cout<<j<<endl;
				cout<<(x+j)/p*q-y;
			}
			else cout<<"0";
		cout<<endl;
		}
		
	}
}
