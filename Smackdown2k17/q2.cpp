#include <iostream>
using namespace std;
int main(){
	int S;
	cin>>S;
	for(int i=0;i<S;i++){
		int N;
		cin>>N;
		int a[N];
		for(int i=0;i<N;i++) cin>>a[i];
		if(N%2==0) {cout<<"no"<<endl;}
		else{
			int flag=1;
			for(int it=0;it<N;it++){
				if(a[it]!=it+1 && it<(N+1)/2){
					flag=0;
				//	cout<<it<<" it"<<endl;
					break;
				}
				else if(a[it]!=N-it && it>=(N+1)/2){
					flag=0;
				//	cout<<it<<" it"<<endl;
					break;
				}
			}
			if(flag==0) cout<<"no"<<endl;
			else cout<<"yes"<<endl;
		}
	}
return 0;
}
