#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int it=0;it<t;it++){
		int length;
		cin>>length;
		char a[length];
		for(int i=0;i<length;i++) cin>>a[i];
		int j=0;
		int count=0;
		int c=1;
		while(j<length){
			if(a[j]=='H' && count%2==0) count++;
			else if(a[j]=='H' && count%2==1) {c=0; break;}
			else if(a[j]=='T' && count%2==1) count++; 
			else if(a[j]=='T' && count%2==0) {c=0; break;}
			j++;
		}	
	if(c==0 || count%2==1) cout<<"Invalid"<<endl;
	else cout<<"Valid"<<endl;
	}
}
